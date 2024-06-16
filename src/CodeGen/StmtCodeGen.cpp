#include "CodeGen/IRGenerator.h"

void IRGenerator::visit(const SharedPtr<ExprStmtNode> &exprStmt) {
    ASTVisitor::visit(exprStmt);
}

void IRGenerator::visit(const SharedPtr<CompoundStmtNode> &compStmt) {
    ASTVisitor::visit(compStmt);
}

void IRGenerator::visit(const SharedPtr<VarDeclStmtNode> &varDeclStmt) {
    ASTVisitor::visit(varDeclStmt);
}

void IRGenerator::visit(const SharedPtr<FunctionDeclStmtNode> &funcDeclStmt) {
    ASTVisitor::visit(funcDeclStmt);
    // 复位插入点
    setFuncInsertPoint(mainFn);
}

void IRGenerator::visit(const SharedPtr<IfStmtNode> &ifStmt) {
    const SharedPtr<Type> conditionType = ifStmt->condition->type;
    ifStmt->condition->accept(shared_from_this());
    ifStmt->thenBB = createBasicBlock("if.then");
    ifStmt->endBB = createBasicBlock("if.end");
    ifStmt->elseBB = ifStmt->endBB;
    if (ifStmt->elseBody) {
        ifStmt->elseBB = createBasicBlock("if.else");
    }

    if(!conditionType->isBoolean()) {
        llvmIRBuilder.CreateCondBr(llvmIRBuilder.getTrue(), ifStmt->thenBB, ifStmt->elseBB);    
    }
    else {
        llvmIRBuilder.CreateCondBr(ifStmt->condition->code, ifStmt->thenBB, ifStmt->elseBB);
    }
    
    emitBlock(ifStmt->thenBB);
    ifStmt->thenBody->accept(shared_from_this());
    emitBranch(ifStmt->endBB);

    if (ifStmt->elseBody) {
        emitBlock(ifStmt->elseBB);
        ifStmt->elseBody->accept(shared_from_this());
        emitBranch(ifStmt->endBB);
    }
    emitBlock(ifStmt->endBB, true);
}

// TODO: break和continue入栈出栈（已写入）
void IRGenerator::visit(const SharedPtr<WhileStmtNode> &whileStmt) {

    whileStmt->condBB = createBasicBlock("while.cond");
    whileStmt->bodyBB = createBasicBlock("while.body");
    whileStmt->endBB = createBasicBlock("while.end");

    breakStack.push_back(whileStmt->endBB);
    continueStack.push_back(whileStmt->condBB);

    emitBlock(whileStmt->condBB);
    whileStmt->condition->accept(shared_from_this());
    llvmIRBuilder.CreateCondBr(whileStmt->condition->code, whileStmt->bodyBB, whileStmt->endBB);

    emitBlock(whileStmt->bodyBB);
    whileStmt->body->accept(shared_from_this());
    emitBranch(whileStmt->condBB);
    emitBlock(whileStmt->endBB, true);

    breakStack.pop_back();
    continueStack.pop_back();
}

// TODO: break和continue入栈出栈（已写入）
void IRGenerator::visit(const SharedPtr<ForStmtNode> &forStmt) {
    if (forStmt->initVarStmt) {
        forStmt->initVarStmt->accept(shared_from_this());
    } else {
        for (const SharedPtr<ExprNode> &initExpr: forStmt->initExprs) {
            initExpr->accept(shared_from_this());
        }
    }
    forStmt->condBB = createBasicBlock("for.cond");
    forStmt->endBB = createBasicBlock("for.end");

    breakStack.push_back(forStmt->endBB);
    continueStack.push_back(forStmt->condBB);

    emitBlock(forStmt->condBB);

    if (!forStmt->updates.empty()) {
        forStmt->updateBB = createBasicBlock("for.update");
    }

    if (forStmt->condition) {
        forStmt->bodyBB = createBasicBlock("for.body");
        forStmt->condition->accept(shared_from_this());
        llvmIRBuilder.CreateCondBr(forStmt->condition->code, forStmt->bodyBB, forStmt->endBB);
        emitBlock(forStmt->bodyBB);
    } else {
        // 如果没有condition, 则把condBB看做bodyBB
    }

    forStmt->body->accept(shared_from_this());

    if (!forStmt->updates.empty()) {
        emitBlock(forStmt->updateBB);
        for (const SharedPtr<ExprNode> &updateExpr: forStmt->updates) {
            updateExpr->accept(shared_from_this());
        }
    }

    emitBranch(forStmt->condBB);
    emitBlock(forStmt->endBB, true);

    breakStack.pop_back();
    continueStack.pop_back();
}

void IRGenerator::visit(const SharedPtr<ContinueStmtNode> &continueStmt) {
    if(!continueStack.empty()) {
        SharedPtr<WhileStmtNode> whileStmt = dynPtrCast<WhileStmtNode>(continueStmt->refIterationStmt);
        if (whileStmt) {
            llvmIRBuilder.CreateBr(whileStmt->condBB);
        } else {
            // 语义分析阶段保证了refIterationStmt不是WhileStmtNode类型就是ForStmtNode类型
            SharedPtr<ForStmtNode> forStmt = dynPtrCast<ForStmtNode>(continueStmt->refIterationStmt);
            llvmIRBuilder.CreateBr(forStmt->updateBB ? forStmt->updateBB : forStmt->condBB);
        }
    }
}

void IRGenerator::visit(const SharedPtr<BreakStmtNode> &breakStmt) {
    if(!breakStack.empty()) {
        SharedPtr<WhileStmtNode> whileStmt = dynPtrCast<WhileStmtNode>(breakStmt->refIterationStmt);
        if (whileStmt) {
            llvmIRBuilder.CreateBr(whileStmt->endBB);
        } else {
            SharedPtr<ForStmtNode> forStmt = dynPtrCast<ForStmtNode>(breakStmt->refIterationStmt);
            llvmIRBuilder.CreateBr(forStmt->endBB);
        }
    }
}

// TODO: 处理函数中间的return语句（已写入）
void IRGenerator::visit(const SharedPtr<ReturnStmtNode> &returnStmt) {
    ASTVisitor::visit(returnStmt);
    const auto &returnExpr = returnStmt->returnExpr;
    const auto &returnType = returnStmt->refFuncDecl->returnType;

    // 新增返回之前的插入点
    llvm::BasicBlock *currentBB = llvmIRBuilder.GetInsertBlock();

    if (returnStmt->returnExpr) {
        if (returnExpr->type->isInteger() && returnType->isFloat()) {
            // 将整型返回值转为浮点型
            returnExpr->code = integer2float(returnExpr->code);
        } else if (returnExpr->type->isFloat() && returnType->isInteger()) {
            // 将浮点返回值转为整型
            returnExpr->code = float2integer(returnExpr->code);
        }

        llvmIRBuilder.CreateRet(returnExpr->code);
    } else {
        llvmIRBuilder.CreateRetVoid();
    }

    // 如果在中间返回
    if(!currentBB->getTerminator()) {
        llvm::BasicBlock *afterReturnBB = llvm::BasicBlock::Create(llvmIRBuilder.getContext(), "after_return", currentBB->getParent());
        // llvmIRBuilder.SetInsertPoint(currentBB);
        llvmIRBuilder.CreateBr(afterReturnBB);
        llvmIRBuilder.SetInsertPoint(afterReturnBB);
    }
}