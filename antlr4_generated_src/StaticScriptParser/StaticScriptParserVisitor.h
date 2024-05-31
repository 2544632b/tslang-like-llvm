
// Generated from /Users/chan/Desktop/StaticScript-master-2/grammar/StaticScriptParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "StaticScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by StaticScriptParser.
 */
class  StaticScriptParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by StaticScriptParser.
   */
    virtual antlrcpp::Any visitModule(StaticScriptParser::ModuleContext *context) = 0;

    virtual antlrcpp::Any visitStatements(StaticScriptParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(StaticScriptParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(StaticScriptParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationStatement(StaticScriptParser::DeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(StaticScriptParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(StaticScriptParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarators(StaticScriptParser::VariableDeclaratorsContext *context) = 0;

    virtual antlrcpp::Any visitVariableModifier(StaticScriptParser::VariableModifierContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarator(StaticScriptParser::VariableDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitVariableInitializer(StaticScriptParser::VariableInitializerContext *context) = 0;

    virtual antlrcpp::Any visitTypeAnnotation(StaticScriptParser::TypeAnnotationContext *context) = 0;

    virtual antlrcpp::Any visitType(StaticScriptParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(StaticScriptParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitBasicType(StaticScriptParser::BasicTypeContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(StaticScriptParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(StaticScriptParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBody(StaticScriptParser::FunctionBodyContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(StaticScriptParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(StaticScriptParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitPrefixUnaryExpr(StaticScriptParser::PrefixUnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpr(StaticScriptParser::IdentifierExprContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpr(StaticScriptParser::BinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitArraySubscriptExpr(StaticScriptParser::ArraySubscriptExprContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpr(StaticScriptParser::LiteralExprContext *context) = 0;

    virtual antlrcpp::Any visitCallExpr(StaticScriptParser::CallExprContext *context) = 0;

    virtual antlrcpp::Any visitPostfixUnaryExpr(StaticScriptParser::PostfixUnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(StaticScriptParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitTernaryExpr(StaticScriptParser::TernaryExprContext *context) = 0;

    virtual antlrcpp::Any visitCallExpression(StaticScriptParser::CallExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(StaticScriptParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(StaticScriptParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitArrayLiteral(StaticScriptParser::ArrayLiteralContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(StaticScriptParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(StaticScriptParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(StaticScriptParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(StaticScriptParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(StaticScriptParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(StaticScriptParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitForInit(StaticScriptParser::ForInitContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(StaticScriptParser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitContinueStatement(StaticScriptParser::ContinueStatementContext *context) = 0;

    virtual antlrcpp::Any visitBreakStatement(StaticScriptParser::BreakStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(StaticScriptParser::ReturnStatementContext *context) = 0;


};

