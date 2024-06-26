#include "Sema/ScopeScanner.h"

void ScopeScanner::visit(const SharedPtr<ModuleNode> &module) {
    SharedPtr<TopLevelScope> topLevelScope = TopLevelScope::create();
    module->internalScope = topLevelScope;
    topLevelScope->host = module;
    pushScope(topLevelScope);
    ASTVisitor::visit(module);
    popScope();
}

void ScopeScanner::visit(const SharedPtr<VarDeclNode> &varDecl) {
    varDecl->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<ParmVarDeclNode> &paramVarDecl) {
    paramVarDecl->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<FunctionDeclNode> &funcDecl) {
    SharedPtr<TopLevelScope> topLevelScope = dynPtrCast<TopLevelScope>(getCurrentScope());
    if (topLevelScope) {
        funcDecl->scope = topLevelScope;
    } else {
        reportSemanticError("Nested functions are not allowed");
    }
    // 函数参数作用域: 在外层作作用域与内层作用域之间的辅助作用域
    SharedPtr<LocalScope> paramScope = LocalScope::create(topLevelScope);
    funcDecl->internalScope = paramScope;
    paramScope->host = funcDecl;
    pushScope(paramScope);
    ASTVisitor::visit(funcDecl);
    popScope();
}

void ScopeScanner::visit(const SharedPtr<BooleanLiteralExprNode> &boolLiteralExpr) {
    boolLiteralExpr->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<IntegerLiteralExprNode> &intLiteralExpr) {
    intLiteralExpr->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<FloatLiteralExprNode> &floatLiteralExpr) {
    floatLiteralExpr->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<StringLiteralExprNode> &strLiteralExpr) {
    strLiteralExpr->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<ArrayLiteralExprNode> &arrayLiteralExpr) {
    arrayLiteralExpr->scope = getCurrentScope();
    ASTVisitor::visit(arrayLiteralExpr);
}

void ScopeScanner::visit(const SharedPtr<IdentifierExprNode> &varExpr) {
    varExpr->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<CallExprNode> &callExpr) {
    callExpr->scope = getCurrentScope();
    ASTVisitor::visit(callExpr);
}

void ScopeScanner::visit(const SharedPtr<UnaryOperatorExprNode> &uopExpr) {
    uopExpr->scope = getCurrentScope();
    ASTVisitor::visit(uopExpr);
}

void ScopeScanner::visit(const SharedPtr<BinaryOperatorExprNode> &bopExpr) {
    bopExpr->scope = getCurrentScope();
    ASTVisitor::visit(bopExpr);
}

void ScopeScanner::visit(const SharedPtr<TernaryOperatorExprNode> &topExpr) {
    topExpr->scope = getCurrentScope();
    ASTVisitor::visit(topExpr);
}

void ScopeScanner::visit(const SharedPtr<ArraySubscriptExprNode> &asExpr) {
    asExpr->scope = getCurrentScope();
    ASTVisitor::visit(asExpr);
}

void ScopeScanner::visit(const SharedPtr<ExprStmtNode> &exprStmt) {
    exprStmt->scope = getCurrentScope();
    ASTVisitor::visit(exprStmt);
}

void ScopeScanner::visit(const SharedPtr<CompoundStmtNode> &compStmt) {
    compStmt->scope = getCurrentScope();
    SharedPtr<LocalScope> blockScope = LocalScope::create(getCurrentScope());
    compStmt->internalScope = blockScope;
    blockScope->host = compStmt;
    pushScope(blockScope);
    ASTVisitor::visit(compStmt);
    popScope();
}

void ScopeScanner::visit(const SharedPtr<VarDeclStmtNode> &varDeclStmt) {
    varDeclStmt->scope = getCurrentScope();
    ASTVisitor::visit(varDeclStmt);
}

void ScopeScanner::visit(const SharedPtr<FunctionDeclStmtNode> &funcDeclStmt) {
    funcDeclStmt->scope = getCurrentScope();
    ASTVisitor::visit(funcDeclStmt);
}

void ScopeScanner::visit(const SharedPtr<IfStmtNode> &ifStmt) {
    ifStmt->scope = getCurrentScope();
    ASTVisitor::visit(ifStmt);
}

void ScopeScanner::visit(const SharedPtr<WhileStmtNode> &whileStmt) {
    whileStmt->scope = getCurrentScope();
    ASTVisitor::visit(whileStmt);
}

void ScopeScanner::visit(const SharedPtr<ForStmtNode> &forStmt) {
    forStmt->scope = getCurrentScope();
    SharedPtr<LocalScope> forScope = LocalScope::create(getCurrentScope());
    forStmt->internalScope = forScope;
    forScope->host = forStmt;
    pushScope(forScope);
    ASTVisitor::visit(forStmt);
    popScope();
}

void ScopeScanner::visit(const SharedPtr<ContinueStmtNode> &continueStmt) {
    continueStmt->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<BreakStmtNode> &breakStmt) {
    breakStmt->scope = getCurrentScope();
}

void ScopeScanner::visit(const SharedPtr<ReturnStmtNode> &returnStmt) {
    returnStmt->scope = getCurrentScope();
    ASTVisitor::visit(returnStmt);
}
