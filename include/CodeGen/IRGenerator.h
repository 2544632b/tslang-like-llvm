#pragma once

#include <algorithm>
#include "StaticScriptLexer.h"
#include "Sema/ASTVisitor.h"
#include "CodeGen/Builtin.h"
#include "Support/Alias.h"
#include "Support/Error.h"
#include "Support/LLVM.h"

class IRGenerator final : public ASTVisitor {
public:
    explicit IRGenerator();

    void resolve(const SharedPtr<ModuleNode> &module, const llvm::Twine &libDir);

    void visit(const SharedPtr<ModuleNode> &module) override;

    void visit(const SharedPtr<VarDeclNode> &varDecl) override;

    void visit(const SharedPtr<ParmVarDeclNode> &paramVarDecl) override;

    void visit(const SharedPtr<FunctionDeclNode> &funcDecl) override;

    void visit(const SharedPtr<BooleanLiteralExprNode> &boolLiteralExpr) override;

    void visit(const SharedPtr<IntegerLiteralExprNode> &intLiteralExpr) override;

    void visit(const SharedPtr<FloatLiteralExprNode> &floatLiteralExpr) override;

    void visit(const SharedPtr<StringLiteralExprNode> &strLiteralExpr) override;

    void visit(const SharedPtr<ArrayLiteralExprNode> &arrayLiteralExpr) override;

    void visit(const SharedPtr<IdentifierExprNode> &varExpr) override;

    void visit(const SharedPtr<CallExprNode> &callExpr) override;

    void visit(const SharedPtr<UnaryOperatorExprNode> &uopExpr) override;

    void visit(const SharedPtr<BinaryOperatorExprNode> &bopExpr) override;

    void visit(const SharedPtr<TernaryOperatorExprNode> &topExpr) override;

    void visit(const SharedPtr<ArraySubscriptExprNode> &asExpr) override;

    void visit(const SharedPtr<ExprStmtNode> &exprStmt) override;

    void visit(const SharedPtr<CompoundStmtNode> &compStmt) override;

    void visit(const SharedPtr<VarDeclStmtNode> &varDeclStmt) override;

    void visit(const SharedPtr<FunctionDeclStmtNode> &funcDeclStmt) override;

    void visit(const SharedPtr<IfStmtNode> &ifStmt) override;

    void visit(const SharedPtr<WhileStmtNode> &whileStmt) override;

    void visit(const SharedPtr<ForStmtNode> &forStmt) override;

    void visit(const SharedPtr<ContinueStmtNode> &continueStmt) override;

    void visit(const SharedPtr<BreakStmtNode> &breakStmt) override;

    void visit(const SharedPtr<ReturnStmtNode> &returnStmt) override;

    LLVMModule &getLLVMModule() const {
        return *llvmModule;
    }

private:
    LLVMType *getType(const SharedPtr<Type> &inputType);

    void setArrayElement(const SharedPtr<ArraySubscriptExprNode> &asExpr, LLVMValue *valueCode);

    inline LLVMValue *float2integer(LLVMValue *val) {
        return llvmIRBuilder.CreateFPToSI(val, llvmIRBuilder.getInt64Ty());
    }

    inline LLVMValue *integer2float(LLVMValue *val) {
        return llvmIRBuilder.CreateSIToFP(val, llvmIRBuilder.getDoubleTy());
    }

    inline void setFuncInsertPoint(LLVMFunction *func) {
        LLVMBasicBlock *curBB = &(func->getBasicBlockList().back());
        llvmIRBuilder.SetInsertPoint(curBB);
    }

    inline LLVMBasicBlock *createBasicBlock(const String &name, LLVMFunction *parent = nullptr, LLVMBasicBlock *before = nullptr) {
        return LLVMBasicBlock::Create(llvmContext, name, parent, before);
    }

    void emitBlock(LLVMBasicBlock *bb, bool isFinished = false);

    void emitBranch(LLVMBasicBlock *targetBB);

    LLVMContext llvmContext;
    llvm::IRBuilder<> llvmIRBuilder;
    SharedPtr<LLVMModule> llvmModule;

    LLVMFunction *mainFn = nullptr;
    LLVMFunction *curFn = nullptr;

    // Patch begin
    std::vector<llvm::BasicBlock*> breakStack;
    std::vector<llvm::BasicBlock*> continueStack;
    // Patch end
};


