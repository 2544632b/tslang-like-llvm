#include "CodeGen/IRGenerator.h"

void IRGenerator::visit(const SharedPtr<BooleanLiteralExprNode> &boolLiteralExpr) {
    boolLiteralExpr->code = boolLiteralExpr->literal ? llvmIRBuilder.getTrue() : llvmIRBuilder.getFalse();
}

void IRGenerator::visit(const SharedPtr<IntegerLiteralExprNode> &intLiteralExpr) {
    intLiteralExpr->code = LLVMConstantInt::get(
            llvmIRBuilder.getInt64Ty(),
            intLiteralExpr->literal,
            true
    );
}

void IRGenerator::visit(const SharedPtr<FloatLiteralExprNode> &floatLiteralExpr) {
    floatLiteralExpr->code = llvm::ConstantFP::get(llvmIRBuilder.getDoubleTy(), floatLiteralExpr->literal);
}

void IRGenerator::visit(const SharedPtr<StringLiteralExprNode> &strLiteralExpr) {
    llvm::Constant *literal = llvmIRBuilder.CreateGlobalString(strLiteralExpr->literal);
    llvm::Value *argLiteral = llvmIRBuilder.CreatePointerCast(literal, llvmIRBuilder.getInt8PtrTy());
    strLiteralExpr->code = llvmIRBuilder.CreateCall(BuiltinString::createFunc, argLiteral);
}

#define GenerateBasicArray(LiteralType, UpperCaseType, AllocaType) \
    llvm::Constant *literalConstants = llvm::ConstantDataArray::get(llvmContext, literalVector); \
    auto *globalLiteralConstants = new LLVMGlobalVariable( \
            *llvmModule, \
            literalConstants->getType(), \
            true, \
            LLVMGlobalValue::PrivateLinkage, \
            literalConstants \
    ); \
    LLVMValue *literalListAlloca = llvmIRBuilder.CreateAlloca( \
            llvm::ArrayType::get(llvmIRBuilder.get##AllocaType##Ty(), elementSize) \
    ); \
    LLVMValue *castedLiteralListLoad = llvmIRBuilder.CreateBitCast(literalListAlloca, llvmIRBuilder.getInt8PtrTy()); \
    LLVMValue *castedLiteralConstants = llvmIRBuilder.CreateBitCast(globalLiteralConstants, llvmIRBuilder.getInt8PtrTy()); \
    Vector<LLVMValue *> memcpyArgs{ \
            castedLiteralListLoad, \
            castedLiteralConstants, \
            llvmIRBuilder.getInt64(sizeof(LiteralType) * elementSize), \
            llvmIRBuilder.getFalse() \
    }; \
    llvmIRBuilder.CreateCall(memcpyFunc, memcpyArgs); \
    LLVMValue *literalListPtr = llvmIRBuilder.CreateInBoundsGEP( \
            literalListAlloca, \
            Vector<LLVMValue *>{ \
                    llvmIRBuilder.getInt64(0), \
                    llvmIRBuilder.getInt64(0) \
            } \
    ); \
    Vector<LLVMValue *> createArgs{literalListPtr, elementSizeCode, errorAlloca}; \
    arrayLiteralExpr->code = llvmIRBuilder.CreateCall(BuiltinArray::create##UpperCaseType##ArrayWithLiteralFunc, createArgs); \

#define GenerateComplexArray(UpperCaseType) \
    LLVMValue *literalListAlloca = llvmIRBuilder.CreateAlloca( \
            llvm::ArrayType::get(Builtin##UpperCaseType::type, elementSize) \
    ); \
    for (size_t i = 0; i < elementSize; ++i) { \
        LLVMValue *literalItemPtr = llvmIRBuilder.CreateInBoundsGEP( \
                literalListAlloca, Vector<LLVMValue *>{ \
                        llvmIRBuilder.getInt64(0), \
                        llvmIRBuilder.getInt64(i) \
                } \
        ); \
        llvmIRBuilder.CreateStore(arrayLiteralExpr->elements[i]->code, literalItemPtr); \
    } \
    LLVMValue *literalListPtr = llvmIRBuilder.CreateInBoundsGEP( \
            literalListAlloca, \
            Vector<LLVMValue *>{ \
                    llvmIRBuilder.getInt64(0), \
                    llvmIRBuilder.getInt64(0) \
            } \
    ); \
    Vector<LLVMValue *> createArgs{literalListPtr, elementSizeCode, errorAlloca}; \
    arrayLiteralExpr->code = llvmIRBuilder.CreateCall(BuiltinArray::create##UpperCaseType##ArrayWithLiteralFunc, createArgs); \


// Create a array
void IRGenerator::visit(const SharedPtr<ArrayLiteralExprNode> &arrayLiteralExpr) {
    const SharedPtr<Type> &elementType = arrayLiteralExpr->type->asArray()->getElementType();

    LLVMValue *errorAlloca = llvmIRBuilder.CreateAlloca(BuiltinError::type);
    llvmIRBuilder.CreateStore(llvm::ConstantPointerNull::get(BuiltinError::type), errorAlloca);
    if (arrayLiteralExpr->elements.empty()) {
        LLVMFunction *createFunc = nullptr;
        if (elementType->isBoolean()) {
            createFunc = BuiltinArray::createBooleanArrayFunc;
        } else if (elementType->isInteger()) {
            createFunc = BuiltinArray::createIntegerArrayFunc;
        } else if (elementType->isFloat()) {
            createFunc = BuiltinArray::createFloatArrayFunc;
        } else if (elementType->isString()) {
            createFunc = BuiltinArray::createStringArrayFunc;
        } else if (elementType->isArray()) {
            createFunc = BuiltinArray::createArrayArrayFunc;
        } else {
            reportTypeError("Array express is empty!");
        }
        arrayLiteralExpr->code = llvmIRBuilder.CreateCall(createFunc, errorAlloca);
    } else {
        // TODO: 优化策略: 当size < 7时, 使用memset+store替代memcpy
        size_t elementSize = arrayLiteralExpr->elements.size();
        LLVMValue *elementSizeCode = llvmIRBuilder.getInt64(elementSize);
        LLVMFunction *memcpyFunc = llvm::Intrinsic::getDeclaration(
                llvmModule.get(),
                llvm::Intrinsic::memcpy,
                Vector<LLVMType *>{
                        llvmIRBuilder.getInt8PtrTy(),
                        llvmIRBuilder.getInt8PtrTy(),
                        llvmIRBuilder.getInt64Ty()
                }
        );
        reportOnCodeGenError(!memcpyFunc, "Not found llvm.memcpy intrinsic function");
        if (elementType->isBoolean()) {
            // 避免使用vector<bool>
            Vector<unsigned char> literalVector(elementSize);
            for (size_t i = 0; i < elementSize; ++i) {
                literalVector[i] = staticPtrCast<BooleanLiteralExprNode>(arrayLiteralExpr->elements[i])->literal;
            }
            GenerateBasicArray(unsigned char, Boolean, Int8)
        } else if (elementType->isInteger()) {
            Vector<long> literalVector(elementSize);
            for (size_t i = 0; i < elementSize; ++i) {
                const SharedPtr<ExprNode> &element = arrayLiteralExpr->elements[i];
                if (const auto &floatElement = dynPtrCast<FloatLiteralExprNode>(element)) {
                    literalVector[i] = floatElement->literal;
                } else if (const auto &intElement = dynPtrCast<IntegerLiteralExprNode>(element)) {
                    literalVector[i] = intElement->literal;
                }
            }
            GenerateBasicArray(long, Integer, Int64)
        } else if (elementType->isFloat()) {
            Vector<double> literalVector(elementSize);
            for (size_t i = 0; i < elementSize; ++i) {
                const SharedPtr<ExprNode> &element = arrayLiteralExpr->elements[i];
                if (const auto &floatElement = dynPtrCast<FloatLiteralExprNode>(element)) {
                    literalVector[i] = floatElement->literal;
                } else if (const auto &intElement = dynPtrCast<IntegerLiteralExprNode>(element)) {
                    literalVector[i] = intElement->literal;
                }
            }
            GenerateBasicArray(double, Float, Double)
        } else if (elementType->isString()) {
            ASTVisitor::visit(arrayLiteralExpr);
            GenerateComplexArray(String)
        } else if (elementType->isArray()) {
            ASTVisitor::visit(arrayLiteralExpr);
            GenerateComplexArray(Array)
        }
    }
    LLVMValue *errorLoad = llvmIRBuilder.CreateLoad(errorAlloca);
    llvmIRBuilder.CreateCall(BuiltinError::exitIfErrorFunc, errorLoad);
}

void IRGenerator::visit(const SharedPtr<IdentifierExprNode> &varExpr) {
    // 按右值处理
    varExpr->code = llvmIRBuilder.CreateLoad(varExpr->refVarDecl->code);
}

void IRGenerator::visit(const SharedPtr<CallExprNode> &callExpr) {
    ASTVisitor::visit(callExpr);
    const SharedPtrVector<ExprNode> &args = callExpr->args;
    const SharedPtrVector<ParmVarDeclNode> &params = callExpr->refFuncDecl->params;
    size_t argsSize = args.size();
    llvm::Function *calleeFunc = llvmModule->getFunction(callExpr->calleeName);
    reportOnCodeGenError(!calleeFunc, "Function '" + callExpr->calleeName + "' is not found");
    if (argsSize != calleeFunc->arg_size()) {
        reportCodeGenError("The number of parameters of function declaration and arguments of call expression does not match");
    }
    Vector<LLVMValue *> argsV;
    for (size_t i = 0, e = argsSize; i != e; ++i) {
        LLVMValue *argV = args[i]->code;
        if (args[i]->type->isInteger() && params[i]->type->isFloat()) {
            // 将整型实参转为浮点型
            argV = integer2float(argV);
        } else if (args[i]->type->isFloat() && params[i]->type->isInteger()) {
            // 将浮点型实参转为整型
            argV = float2integer(argV);
        }
        argsV.push_back(argV);
    }
    callExpr->code = llvmIRBuilder.CreateCall(calleeFunc, argsV);
}

void IRGenerator::visit(const SharedPtr<UnaryOperatorExprNode> &uopExpr) {
    ASTVisitor::visit(uopExpr);

    SharedPtr<ExprNode> subExpr = uopExpr->subExpr;

    bool isFloat = uopExpr->subExpr->type->isFloat();

    switch (uopExpr->opCode) {
        case StaticScriptLexer::PlusPlus:
        case StaticScriptLexer::MinusMinus: {
            LLVMValue *value = subExpr->code;
            LLVMValue *newValue;
            if (isFloat) {
                llvm::Constant *one = llvm::ConstantFP::get(llvmIRBuilder.getDoubleTy(), 1.0);
                if (uopExpr->opCode == StaticScriptLexer::PlusPlus) {
                    newValue = llvmIRBuilder.CreateFAdd(value, one);
                } else {
                    newValue = llvmIRBuilder.CreateFSub(value, one);
                }
            } else {
                LLVMConstantInt *one = llvmIRBuilder.getInt64(1);
                if (uopExpr->opCode == StaticScriptLexer::PlusPlus) {
                    newValue = llvmIRBuilder.CreateNSWAdd(value, one);
                } else {
                    newValue = llvmIRBuilder.CreateNSWSub(value, one);
                }
            }
            if (const auto &subVarExpr = dynPtrCast<IdentifierExprNode>(subExpr)) {
                llvmIRBuilder.CreateStore(newValue, subVarExpr->refVarDecl->code);
            } else if (const auto &asExpr = dynPtrCast<ArraySubscriptExprNode>(subExpr)) {
                setArrayElement(asExpr, newValue);
            }
            uopExpr->code = uopExpr->isPostfix ? value : newValue;
            break;
        }
        case StaticScriptLexer::Not: {
            uopExpr->code = llvmIRBuilder.CreateXor(subExpr->code, llvmIRBuilder.getTrue());
            break;
        }
        case StaticScriptLexer::BitNot: {
            uopExpr->code = llvmIRBuilder.CreateXor(subExpr->code, llvmIRBuilder.getInt64(-1));
            break;
        }
        case StaticScriptLexer::Plus: {
            uopExpr->code = subExpr->code;
            break;
        }
        case StaticScriptLexer::Minus: {
            if (isFloat) {
                uopExpr->code = llvmIRBuilder.CreateFNeg(subExpr->code);
            } else {
                uopExpr->code = llvmIRBuilder.CreateNSWNeg(subExpr->code);
            }
            break;
        }
    }
}

// IR begin

LLVMValue* generateNullishCoalescing(LLVMValue* lhs, LLVMValue* rhs, llvm::IRBuilder<> &builder) {
    llvm::Function* function = builder.GetInsertBlock()->getParent();
    llvm::LLVMContext &context = builder.getContext();

    llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "then", function);
    llvm::BasicBlock* elseBB = llvm::BasicBlock::Create(context, "else");
    llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "ifcont");

    llvm::Value* lhsIsNull;
    if (lhs->getType()->isFloatingPointTy()) {
        llvm::Value* lhsAsInt = builder.CreateFPToSI(lhs, llvm::Type::getInt64Ty(context));
        lhsIsNull = builder.CreateICmpEQ(lhsAsInt, llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0));
    } else if (lhs->getType()->isIntegerTy(64)) {
        lhsIsNull = builder.CreateICmpEQ(lhs, llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0));
    } else if (lhs->getType()->isStructTy()) {
        llvm::StructType *sType = llvm::dyn_cast<llvm::StructType>(lhs->getType());
        if(sType->hasName()) {
            llvm::StringRef typeName = sType->getName();
            if(typeName == "struct.type_string") {
                llvm::Value* result = builder.CreateCall(BuiltinString::stringSizeFunc, lhs, "call_string_size");
                lhsIsNull = builder.CreateICmpEQ(result, llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0), "cmp_zero");
            } else {
                lhsIsNull = builder.getFalse();
            }
        } else {
            lhsIsNull = builder.getFalse();
        }
    } else if (lhs->getType()->isPointerTy()) {
        llvm::Type *elementType = lhs->getType()->getPointerElementType();
        llvm::StructType *structType = llvm::dyn_cast<llvm::StructType>(elementType);
        if(structType->hasName()) {
            llvm::StringRef typeName = structType->getName();
            if(typeName == "struct.type_string") {
                llvm::Value* result = builder.CreateCall(BuiltinString::stringSizeFunc, lhs, "call_string_size");
                lhsIsNull = builder.CreateICmpEQ(result, llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0), "cmp_zero");
            } else {
                lhsIsNull = builder.getFalse();
            }
        }
    } else {
        lhsIsNull = builder.getFalse();
    }

    builder.CreateCondBr(lhsIsNull, thenBB, elseBB);

    // Then block: lhs is null
    builder.SetInsertPoint(thenBB);
    llvm::Value* thenValue = rhs;
    builder.CreateBr(mergeBB);
    thenBB = builder.GetInsertBlock();

    // Else block: lhs is not null
    function->getBasicBlockList().push_back(elseBB);
    builder.SetInsertPoint(elseBB);
    llvm::Value* elseValue = lhs;
    builder.CreateBr(mergeBB);
    elseBB = builder.GetInsertBlock();

    // Merge block
    function->getBasicBlockList().push_back(mergeBB);
    builder.SetInsertPoint(mergeBB);
    llvm::PHINode* phiNode = builder.CreatePHI(lhs->getType(), 2);
    phiNode->addIncoming(thenValue, thenBB);
    phiNode->addIncoming(elseValue, elseBB);

    return phiNode;
}

// IR end

void IRGenerator::visit(const SharedPtr<BinaryOperatorExprNode> &bopExpr) {
    unsigned int bopCode = bopExpr->opCode;
    // 变量被赋值时只需要visit lhs
    if (bopCode == StaticScriptLexer::Assign && dynPtrCast<IdentifierExprNode>(bopExpr->lhs)) {
        bopExpr->rhs->accept(shared_from_this());
    } else {
        ASTVisitor::visit(bopExpr);
    }

    const SharedPtr<Type> &leftType = bopExpr->lhs->type;
    const SharedPtr<Type> &rightType = bopExpr->rhs->type;
    LLVMValue *lhsCode = bopExpr->lhs->code;
    LLVMValue *rhsCode = bopExpr->rhs->code;
    LLVMValue *targetCode = nullptr;

    SharedPtr<Type> type = leftType;
    SharedPtr<Type> rtype = rightType;

    if (leftType->isInteger() && rightType->isFloat() && bopCode != StaticScriptLexer::Assign) {
        type = rightType;
        lhsCode = integer2float(lhsCode);
    } else if (leftType->isFloat() && rightType->isInteger()) {
        rhsCode = integer2float(rhsCode);
    }

    switch (bopCode) {
        case StaticScriptLexer::Plus:
        case StaticScriptLexer::PlusAssign: {
            if (type->isString()) {
                Vector<LLVMValue *> argsV{lhsCode, rhsCode};
                targetCode = llvmIRBuilder.CreateCall(BuiltinString::concatFunc, argsV);
            } else if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateNSWAdd(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFAdd(lhsCode, rhsCode);
            } else if (rtype->isString()) {
                if(bopCode != StaticScriptLexer::PlusAssign) {
                    Vector<LLVMValue *> argsV{lhsCode, rhsCode};
                    targetCode = llvmIRBuilder.CreateCall(BuiltinString::concatFunc, argsV);
                }
            }
            break;
        }
        case StaticScriptLexer::Minus:
        case StaticScriptLexer::MinusAssign: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateNSWSub(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFSub(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::Multiply:
        case StaticScriptLexer::MultiplyAssign: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateNSWMul(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFMul(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::Divide:
        case StaticScriptLexer::DivideAssign: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateSDiv(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFDiv(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::Modulus:
        case StaticScriptLexer::ModulusAssign: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateSRem(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFRem(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::BitAnd:
        case StaticScriptLexer::BitAndAssign: {
            targetCode = llvmIRBuilder.CreateAnd(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::BitXOr:
        case StaticScriptLexer::BitXorAssign: {
            targetCode = llvmIRBuilder.CreateXor(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::BitOr:
        case StaticScriptLexer::BitOrAssign: {
            targetCode = llvmIRBuilder.CreateOr(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::ShiftLeft:
        case StaticScriptLexer::ShiftLeftAssign: {
            targetCode = llvmIRBuilder.CreateShl(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::ArithmeticShiftRight:
        case StaticScriptLexer::ArithmeticShiftRightAssign: {
            targetCode = llvmIRBuilder.CreateAShr(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::LogicalShiftRight:
        case StaticScriptLexer::LogicalShiftRightAssign: {
            targetCode = llvmIRBuilder.CreateLShr(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::And:
        case StaticScriptLexer::AndAssign: {
            targetCode = llvmIRBuilder.CreateAnd(lhsCode, rhsCode);
            break;
        }
        case StaticScriptLexer::Or:
        case StaticScriptLexer::OrAssign: {
            targetCode = llvmIRBuilder.CreateOr(lhsCode, rhsCode);
            break;
        }
        
        case StaticScriptLexer::Nullish: {
            targetCode = generateNullishCoalescing(lhsCode, rhsCode, llvmIRBuilder);

            break;
        }
        case StaticScriptLexer::LessThan: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpSLT(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpOLE(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::GreaterThan: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpSGT(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpOGT(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::LessThanEquals: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpSLE(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpOLE(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::GreaterThanEquals: {
            if (type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpSGE(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpOGE(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::Equals: {
            if (type->isString()) {
                Vector<LLVMValue *> argsV{lhsCode, rhsCode};
                LLVMValue *relationship = llvmIRBuilder.CreateCall(BuiltinString::equalsFunc, argsV);
                targetCode = llvmIRBuilder.CreateICmpEQ(relationship, llvmIRBuilder.getInt64(0));
            } else if (type->isBoolean() || type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpEQ(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpOEQ(lhsCode, rhsCode);
            }
            break;
        }
        case StaticScriptLexer::NotEquals: {
            if (type->isString()) {
                Vector<LLVMValue *> argsV{lhsCode, rhsCode};
                LLVMValue *relationship = llvmIRBuilder.CreateCall(BuiltinString::equalsFunc, argsV);
                targetCode = llvmIRBuilder.CreateICmpNE(relationship, llvmIRBuilder.getInt64(0));
            } else if (type->isBoolean() || type->isInteger()) {
                targetCode = llvmIRBuilder.CreateICmpNE(lhsCode, rhsCode);
            } else if (type->isFloat()) {
                targetCode = llvmIRBuilder.CreateFCmpONE(lhsCode, rhsCode);
            }
            break;
        }
        default:
            break;
    }
    if (bopCode >= StaticScriptLexer::Assign && bopCode <= StaticScriptLexer::OrAssign) {
        // 在语义阶段保证lhs类型为IdentifierExprNode或者ArraySubscriptExprNode

        // 简单赋值时直接把targetCode设置为rhsCode
        if (bopCode == StaticScriptLexer::Assign) {
            targetCode = rhsCode;
        }

        // 赋值/算术类型复合赋值时整型与浮点型的转换机制
        if (bopCode >= StaticScriptLexer::Assign && bopCode <= StaticScriptLexer::ModulusAssign) {
            if (leftType->isInteger() && rightType->isFloat()) {
                targetCode = float2integer(targetCode);
            } else if (leftType->isFloat() && rightType->isInteger()) {
                targetCode = integer2float(targetCode);
            }
        }

        if (const auto &leftVarExpr = dynPtrCast<IdentifierExprNode>(bopExpr->lhs)) {
            llvmIRBuilder.CreateStore(targetCode, leftVarExpr->refVarDecl->code);
        } else if (const auto &leftAsExpr = dynPtrCast<ArraySubscriptExprNode>(bopExpr->lhs)) {
            setArrayElement(leftAsExpr, targetCode);
        } else {
            reportCodeGenError("No assignment code was generated");
        }
    }
    bopExpr->code = targetCode;
}

void IRGenerator::visit(const SharedPtr<TernaryOperatorExprNode> &topExpr) {
    ASTVisitor::visit(topExpr);
    
    LLVMValue *targetCode = nullptr;
    LLVMValue *boolCode = topExpr->bhs->code;
    LLVMValue *lhsCode = topExpr->lhs->code;
    LLVMValue *rhsCode = topExpr->rhs->code;

    if(lhsCode->getType() != rhsCode->getType()) {
        reportTypeError("It should be same when using the ternary.");
    }

    // Create the basick block
    llvm::Function *function = llvmIRBuilder.GetInsertBlock()->getParent();
    llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(llvmIRBuilder.getContext(), "then", function);
    llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(llvmIRBuilder.getContext(), "else");
    llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(llvmIRBuilder.getContext(), "ifcont");

    // If IR
    llvmIRBuilder.CreateCondBr(boolCode, thenBB, elseBB);

    // then IR
    llvmIRBuilder.SetInsertPoint(thenBB);
    llvmIRBuilder.CreateBr(mergeBB);
    llvmIRBuilder.GetInsertBlock();

    // else IR
    function->getBasicBlockList().push_back(elseBB);
    llvmIRBuilder.SetInsertPoint(elseBB);
    llvmIRBuilder.CreateBr(mergeBB);
    elseBB = llvmIRBuilder.GetInsertBlock();

    // emit branches
    function->getBasicBlockList().push_back(mergeBB);
    llvmIRBuilder.SetInsertPoint(mergeBB);

    // Set a value for PHI
    llvm::PHINode *phiNode = llvmIRBuilder.CreatePHI(lhsCode->getType(), 2, "iftmp");
    phiNode->addIncoming(lhsCode, thenBB);
    phiNode->addIncoming(rhsCode, elseBB);

    topExpr->code = phiNode;
}


// Get a element
void IRGenerator::visit(const SharedPtr<ArraySubscriptExprNode> &asExpr) {
    ASTVisitor::visit(asExpr);
    SharedPtr<Type> iterType = asExpr->baseExpr->type;
    LLVMValue *iterCode = asExpr->baseExpr->code;
    LLVMValue *errorAlloca = llvmIRBuilder.CreateAlloca(BuiltinError::type);
    llvmIRBuilder.CreateStore(llvm::ConstantPointerNull::get(BuiltinError::type), errorAlloca);
    for (const SharedPtr<ExprNode> &indexExpr: asExpr->indexExprs) {
        LLVMFunction *getFunc = nullptr;
        SharedPtr<Type> iterEleType = iterType->asArray()->getElementType();
        if (iterEleType->isBoolean()) {
            getFunc = BuiltinArray::getBooleanFunc;
        } else if (iterEleType->isInteger()) {
            getFunc = BuiltinArray::getIntegerFunc;
        } else if (iterEleType->isFloat()) {
            getFunc = BuiltinArray::getFloatFunc;
        } else if (iterEleType->isString()) {
            getFunc = BuiltinArray::getStringFunc;
        } else if (iterEleType->isArray()) {
            getFunc = BuiltinArray::getArrayFunc;
        }
        
        iterType = iterEleType;
        iterCode = llvmIRBuilder.CreateCall(getFunc, Vector<LLVMValue *>{iterCode, indexExpr->code, errorAlloca});
        LLVMValue *errorLoad = llvmIRBuilder.CreateLoad(errorAlloca);
        llvmIRBuilder.CreateCall(BuiltinError::exitIfErrorFunc, errorLoad);
    }
    asExpr->code = iterCode;
}