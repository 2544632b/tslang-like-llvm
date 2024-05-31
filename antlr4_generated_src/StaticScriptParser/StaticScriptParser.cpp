
// Generated from /Users/chan/Desktop/StaticScript-master-2/grammar/StaticScriptParser.g4 by ANTLR 4.9.2


#include "StaticScriptParserVisitor.h"

#include "StaticScriptParser.h"


using namespace antlrcpp;
using namespace antlr4;

StaticScriptParser::StaticScriptParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

StaticScriptParser::~StaticScriptParser() {
  delete _interpreter;
}

std::string StaticScriptParser::getGrammarFileName() const {
  return "StaticScriptParser.g4";
}

const std::vector<std::string>& StaticScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& StaticScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ModuleContext ------------------------------------------------------------------

StaticScriptParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::ModuleContext::EOF() {
  return getToken(StaticScriptParser::EOF, 0);
}

StaticScriptParser::StatementsContext* StaticScriptParser::ModuleContext::statements() {
  return getRuleContext<StaticScriptParser::StatementsContext>(0);
}


size_t StaticScriptParser::ModuleContext::getRuleIndex() const {
  return StaticScriptParser::RuleModule;
}


antlrcpp::Any StaticScriptParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ModuleContext* StaticScriptParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 0, StaticScriptParser::RuleModule);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StaticScriptParser::Let)
      | (1ULL << StaticScriptParser::Const)
      | (1ULL << StaticScriptParser::If)
      | (1ULL << StaticScriptParser::For)
      | (1ULL << StaticScriptParser::While)
      | (1ULL << StaticScriptParser::Break)
      | (1ULL << StaticScriptParser::Continue)
      | (1ULL << StaticScriptParser::Function)
      | (1ULL << StaticScriptParser::Return)
      | (1ULL << StaticScriptParser::OpenParen)
      | (1ULL << StaticScriptParser::OpenBracket)
      | (1ULL << StaticScriptParser::OpenBrace)
      | (1ULL << StaticScriptParser::SemiColon)
      | (1ULL << StaticScriptParser::PlusPlus)
      | (1ULL << StaticScriptParser::MinusMinus)
      | (1ULL << StaticScriptParser::Not)
      | (1ULL << StaticScriptParser::BitNot)
      | (1ULL << StaticScriptParser::Plus)
      | (1ULL << StaticScriptParser::Minus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (StaticScriptParser::BooleanLiteral - 64))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::FloatLiteral - 64))
      | (1ULL << (StaticScriptParser::StringLiteral - 64))
      | (1ULL << (StaticScriptParser::Identifier - 64)))) != 0)) {
      setState(72);
      statements();
    }
    setState(75);
    match(StaticScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

StaticScriptParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StaticScriptParser::StatementContext *> StaticScriptParser::StatementsContext::statement() {
  return getRuleContexts<StaticScriptParser::StatementContext>();
}

StaticScriptParser::StatementContext* StaticScriptParser::StatementsContext::statement(size_t i) {
  return getRuleContext<StaticScriptParser::StatementContext>(i);
}


size_t StaticScriptParser::StatementsContext::getRuleIndex() const {
  return StaticScriptParser::RuleStatements;
}


antlrcpp::Any StaticScriptParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::StatementsContext* StaticScriptParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, StaticScriptParser::RuleStatements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(77);
      statement();
      setState(80); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StaticScriptParser::Let)
      | (1ULL << StaticScriptParser::Const)
      | (1ULL << StaticScriptParser::If)
      | (1ULL << StaticScriptParser::For)
      | (1ULL << StaticScriptParser::While)
      | (1ULL << StaticScriptParser::Break)
      | (1ULL << StaticScriptParser::Continue)
      | (1ULL << StaticScriptParser::Function)
      | (1ULL << StaticScriptParser::Return)
      | (1ULL << StaticScriptParser::OpenParen)
      | (1ULL << StaticScriptParser::OpenBracket)
      | (1ULL << StaticScriptParser::OpenBrace)
      | (1ULL << StaticScriptParser::SemiColon)
      | (1ULL << StaticScriptParser::PlusPlus)
      | (1ULL << StaticScriptParser::MinusMinus)
      | (1ULL << StaticScriptParser::Not)
      | (1ULL << StaticScriptParser::BitNot)
      | (1ULL << StaticScriptParser::Plus)
      | (1ULL << StaticScriptParser::Minus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (StaticScriptParser::BooleanLiteral - 64))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::FloatLiteral - 64))
      | (1ULL << (StaticScriptParser::StringLiteral - 64))
      | (1ULL << (StaticScriptParser::Identifier - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

StaticScriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::EmptyStatementContext* StaticScriptParser::StatementContext::emptyStatement() {
  return getRuleContext<StaticScriptParser::EmptyStatementContext>(0);
}

StaticScriptParser::DeclarationStatementContext* StaticScriptParser::StatementContext::declarationStatement() {
  return getRuleContext<StaticScriptParser::DeclarationStatementContext>(0);
}

StaticScriptParser::CompoundStatementContext* StaticScriptParser::StatementContext::compoundStatement() {
  return getRuleContext<StaticScriptParser::CompoundStatementContext>(0);
}

StaticScriptParser::ExpressionStatementContext* StaticScriptParser::StatementContext::expressionStatement() {
  return getRuleContext<StaticScriptParser::ExpressionStatementContext>(0);
}

StaticScriptParser::SelectionStatementContext* StaticScriptParser::StatementContext::selectionStatement() {
  return getRuleContext<StaticScriptParser::SelectionStatementContext>(0);
}

StaticScriptParser::IterationStatementContext* StaticScriptParser::StatementContext::iterationStatement() {
  return getRuleContext<StaticScriptParser::IterationStatementContext>(0);
}

StaticScriptParser::JumpStatementContext* StaticScriptParser::StatementContext::jumpStatement() {
  return getRuleContext<StaticScriptParser::JumpStatementContext>(0);
}


size_t StaticScriptParser::StatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleStatement;
}


antlrcpp::Any StaticScriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::StatementContext* StaticScriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, StaticScriptParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::SemiColon: {
        enterOuterAlt(_localctx, 1);
        setState(82);
        emptyStatement();
        break;
      }

      case StaticScriptParser::Let:
      case StaticScriptParser::Const:
      case StaticScriptParser::Function: {
        enterOuterAlt(_localctx, 2);
        setState(83);
        declarationStatement();
        break;
      }

      case StaticScriptParser::OpenBrace: {
        enterOuterAlt(_localctx, 3);
        setState(84);
        compoundStatement();
        break;
      }

      case StaticScriptParser::OpenParen:
      case StaticScriptParser::OpenBracket:
      case StaticScriptParser::PlusPlus:
      case StaticScriptParser::MinusMinus:
      case StaticScriptParser::Not:
      case StaticScriptParser::BitNot:
      case StaticScriptParser::Plus:
      case StaticScriptParser::Minus:
      case StaticScriptParser::BooleanLiteral:
      case StaticScriptParser::DecimalIntegerLiteral:
      case StaticScriptParser::HexIntegerLiteral:
      case StaticScriptParser::OctalIntegerLiteral:
      case StaticScriptParser::BinaryIntegerLiteral:
      case StaticScriptParser::FloatLiteral:
      case StaticScriptParser::StringLiteral:
      case StaticScriptParser::Identifier: {
        enterOuterAlt(_localctx, 4);
        setState(85);
        expressionStatement();
        break;
      }

      case StaticScriptParser::If: {
        enterOuterAlt(_localctx, 5);
        setState(86);
        selectionStatement();
        break;
      }

      case StaticScriptParser::For:
      case StaticScriptParser::While: {
        enterOuterAlt(_localctx, 6);
        setState(87);
        iterationStatement();
        break;
      }

      case StaticScriptParser::Break:
      case StaticScriptParser::Continue:
      case StaticScriptParser::Return: {
        enterOuterAlt(_localctx, 7);
        setState(88);
        jumpStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

StaticScriptParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::EmptyStatementContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}


size_t StaticScriptParser::EmptyStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleEmptyStatement;
}


antlrcpp::Any StaticScriptParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::EmptyStatementContext* StaticScriptParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, StaticScriptParser::RuleEmptyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationStatementContext ------------------------------------------------------------------

StaticScriptParser::DeclarationStatementContext::DeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::DeclarationContext* StaticScriptParser::DeclarationStatementContext::declaration() {
  return getRuleContext<StaticScriptParser::DeclarationContext>(0);
}


size_t StaticScriptParser::DeclarationStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleDeclarationStatement;
}


antlrcpp::Any StaticScriptParser::DeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::DeclarationStatementContext* StaticScriptParser::declarationStatement() {
  DeclarationStatementContext *_localctx = _tracker.createInstance<DeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, StaticScriptParser::RuleDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

StaticScriptParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::VariableDeclarationContext* StaticScriptParser::DeclarationContext::variableDeclaration() {
  return getRuleContext<StaticScriptParser::VariableDeclarationContext>(0);
}

StaticScriptParser::FunctionDeclarationContext* StaticScriptParser::DeclarationContext::functionDeclaration() {
  return getRuleContext<StaticScriptParser::FunctionDeclarationContext>(0);
}


size_t StaticScriptParser::DeclarationContext::getRuleIndex() const {
  return StaticScriptParser::RuleDeclaration;
}


antlrcpp::Any StaticScriptParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::DeclarationContext* StaticScriptParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, StaticScriptParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::Let:
      case StaticScriptParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        variableDeclaration();
        break;
      }

      case StaticScriptParser::Function: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        functionDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

StaticScriptParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::VariableDeclaratorsContext* StaticScriptParser::VariableDeclarationContext::variableDeclarators() {
  return getRuleContext<StaticScriptParser::VariableDeclaratorsContext>(0);
}

tree::TerminalNode* StaticScriptParser::VariableDeclarationContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}


size_t StaticScriptParser::VariableDeclarationContext::getRuleIndex() const {
  return StaticScriptParser::RuleVariableDeclaration;
}


antlrcpp::Any StaticScriptParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::VariableDeclarationContext* StaticScriptParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, StaticScriptParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    variableDeclarators();
    setState(100);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorsContext ------------------------------------------------------------------

StaticScriptParser::VariableDeclaratorsContext::VariableDeclaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::VariableModifierContext* StaticScriptParser::VariableDeclaratorsContext::variableModifier() {
  return getRuleContext<StaticScriptParser::VariableModifierContext>(0);
}

std::vector<StaticScriptParser::VariableDeclaratorContext *> StaticScriptParser::VariableDeclaratorsContext::variableDeclarator() {
  return getRuleContexts<StaticScriptParser::VariableDeclaratorContext>();
}

StaticScriptParser::VariableDeclaratorContext* StaticScriptParser::VariableDeclaratorsContext::variableDeclarator(size_t i) {
  return getRuleContext<StaticScriptParser::VariableDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::VariableDeclaratorsContext::Comma() {
  return getTokens(StaticScriptParser::Comma);
}

tree::TerminalNode* StaticScriptParser::VariableDeclaratorsContext::Comma(size_t i) {
  return getToken(StaticScriptParser::Comma, i);
}


size_t StaticScriptParser::VariableDeclaratorsContext::getRuleIndex() const {
  return StaticScriptParser::RuleVariableDeclarators;
}


antlrcpp::Any StaticScriptParser::VariableDeclaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarators(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::VariableDeclaratorsContext* StaticScriptParser::variableDeclarators() {
  VariableDeclaratorsContext *_localctx = _tracker.createInstance<VariableDeclaratorsContext>(_ctx, getState());
  enterRule(_localctx, 14, StaticScriptParser::RuleVariableDeclarators);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    variableModifier();
    setState(103);
    variableDeclarator();
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StaticScriptParser::Comma) {
      setState(104);
      match(StaticScriptParser::Comma);
      setState(105);
      variableDeclarator();
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableModifierContext ------------------------------------------------------------------

StaticScriptParser::VariableModifierContext::VariableModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::VariableModifierContext::Let() {
  return getToken(StaticScriptParser::Let, 0);
}

tree::TerminalNode* StaticScriptParser::VariableModifierContext::Const() {
  return getToken(StaticScriptParser::Const, 0);
}


size_t StaticScriptParser::VariableModifierContext::getRuleIndex() const {
  return StaticScriptParser::RuleVariableModifier;
}


antlrcpp::Any StaticScriptParser::VariableModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableModifier(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::VariableModifierContext* StaticScriptParser::variableModifier() {
  VariableModifierContext *_localctx = _tracker.createInstance<VariableModifierContext>(_ctx, getState());
  enterRule(_localctx, 16, StaticScriptParser::RuleVariableModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _la = _input->LA(1);
    if (!(_la == StaticScriptParser::Let

    || _la == StaticScriptParser::Const)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorContext ------------------------------------------------------------------

StaticScriptParser::VariableDeclaratorContext::VariableDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::VariableDeclaratorContext::Identifier() {
  return getToken(StaticScriptParser::Identifier, 0);
}

StaticScriptParser::TypeAnnotationContext* StaticScriptParser::VariableDeclaratorContext::typeAnnotation() {
  return getRuleContext<StaticScriptParser::TypeAnnotationContext>(0);
}

StaticScriptParser::VariableInitializerContext* StaticScriptParser::VariableDeclaratorContext::variableInitializer() {
  return getRuleContext<StaticScriptParser::VariableInitializerContext>(0);
}


size_t StaticScriptParser::VariableDeclaratorContext::getRuleIndex() const {
  return StaticScriptParser::RuleVariableDeclarator;
}


antlrcpp::Any StaticScriptParser::VariableDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarator(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::VariableDeclaratorContext* StaticScriptParser::variableDeclarator() {
  VariableDeclaratorContext *_localctx = _tracker.createInstance<VariableDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 18, StaticScriptParser::RuleVariableDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(StaticScriptParser::Identifier);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StaticScriptParser::Colon) {
      setState(114);
      typeAnnotation();
    }
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StaticScriptParser::Assign) {
      setState(117);
      variableInitializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableInitializerContext ------------------------------------------------------------------

StaticScriptParser::VariableInitializerContext::VariableInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::VariableInitializerContext::Assign() {
  return getToken(StaticScriptParser::Assign, 0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::VariableInitializerContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}


size_t StaticScriptParser::VariableInitializerContext::getRuleIndex() const {
  return StaticScriptParser::RuleVariableInitializer;
}


antlrcpp::Any StaticScriptParser::VariableInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableInitializer(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::VariableInitializerContext* StaticScriptParser::variableInitializer() {
  VariableInitializerContext *_localctx = _tracker.createInstance<VariableInitializerContext>(_ctx, getState());
  enterRule(_localctx, 20, StaticScriptParser::RuleVariableInitializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(StaticScriptParser::Assign);
    setState(121);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAnnotationContext ------------------------------------------------------------------

StaticScriptParser::TypeAnnotationContext::TypeAnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::TypeAnnotationContext::Colon() {
  return getToken(StaticScriptParser::Colon, 0);
}

StaticScriptParser::TypeContext* StaticScriptParser::TypeAnnotationContext::type() {
  return getRuleContext<StaticScriptParser::TypeContext>(0);
}


size_t StaticScriptParser::TypeAnnotationContext::getRuleIndex() const {
  return StaticScriptParser::RuleTypeAnnotation;
}


antlrcpp::Any StaticScriptParser::TypeAnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitTypeAnnotation(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::TypeAnnotationContext* StaticScriptParser::typeAnnotation() {
  TypeAnnotationContext *_localctx = _tracker.createInstance<TypeAnnotationContext>(_ctx, getState());
  enterRule(_localctx, 22, StaticScriptParser::RuleTypeAnnotation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(StaticScriptParser::Colon);
    setState(124);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

StaticScriptParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::ArrayTypeContext* StaticScriptParser::TypeContext::arrayType() {
  return getRuleContext<StaticScriptParser::ArrayTypeContext>(0);
}

StaticScriptParser::BasicTypeContext* StaticScriptParser::TypeContext::basicType() {
  return getRuleContext<StaticScriptParser::BasicTypeContext>(0);
}


size_t StaticScriptParser::TypeContext::getRuleIndex() const {
  return StaticScriptParser::RuleType;
}


antlrcpp::Any StaticScriptParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::TypeContext* StaticScriptParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 24, StaticScriptParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(126);
      arrayType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      basicType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

StaticScriptParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::BasicTypeContext* StaticScriptParser::ArrayTypeContext::basicType() {
  return getRuleContext<StaticScriptParser::BasicTypeContext>(0);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ArrayTypeContext::OpenBracket() {
  return getTokens(StaticScriptParser::OpenBracket);
}

tree::TerminalNode* StaticScriptParser::ArrayTypeContext::OpenBracket(size_t i) {
  return getToken(StaticScriptParser::OpenBracket, i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ArrayTypeContext::CloseBracket() {
  return getTokens(StaticScriptParser::CloseBracket);
}

tree::TerminalNode* StaticScriptParser::ArrayTypeContext::CloseBracket(size_t i) {
  return getToken(StaticScriptParser::CloseBracket, i);
}


size_t StaticScriptParser::ArrayTypeContext::getRuleIndex() const {
  return StaticScriptParser::RuleArrayType;
}


antlrcpp::Any StaticScriptParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ArrayTypeContext* StaticScriptParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, StaticScriptParser::RuleArrayType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    basicType();
    setState(133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(131);
      match(StaticScriptParser::OpenBracket);
      setState(132);
      match(StaticScriptParser::CloseBracket);
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == StaticScriptParser::OpenBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

StaticScriptParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::BasicTypeContext::Boolean() {
  return getToken(StaticScriptParser::Boolean, 0);
}

tree::TerminalNode* StaticScriptParser::BasicTypeContext::Integer() {
  return getToken(StaticScriptParser::Integer, 0);
}

tree::TerminalNode* StaticScriptParser::BasicTypeContext::Number() {
  return getToken(StaticScriptParser::Number, 0);
}

tree::TerminalNode* StaticScriptParser::BasicTypeContext::String() {
  return getToken(StaticScriptParser::String, 0);
}


size_t StaticScriptParser::BasicTypeContext::getRuleIndex() const {
  return StaticScriptParser::RuleBasicType;
}


antlrcpp::Any StaticScriptParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::BasicTypeContext* StaticScriptParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 28, StaticScriptParser::RuleBasicType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StaticScriptParser::Boolean)
      | (1ULL << StaticScriptParser::Integer)
      | (1ULL << StaticScriptParser::Number)
      | (1ULL << StaticScriptParser::String))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

StaticScriptParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::FunctionDeclarationContext::Function() {
  return getToken(StaticScriptParser::Function, 0);
}

tree::TerminalNode* StaticScriptParser::FunctionDeclarationContext::Identifier() {
  return getToken(StaticScriptParser::Identifier, 0);
}

tree::TerminalNode* StaticScriptParser::FunctionDeclarationContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

tree::TerminalNode* StaticScriptParser::FunctionDeclarationContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::FunctionBodyContext* StaticScriptParser::FunctionDeclarationContext::functionBody() {
  return getRuleContext<StaticScriptParser::FunctionBodyContext>(0);
}

StaticScriptParser::ParameterListContext* StaticScriptParser::FunctionDeclarationContext::parameterList() {
  return getRuleContext<StaticScriptParser::ParameterListContext>(0);
}

StaticScriptParser::TypeAnnotationContext* StaticScriptParser::FunctionDeclarationContext::typeAnnotation() {
  return getRuleContext<StaticScriptParser::TypeAnnotationContext>(0);
}


size_t StaticScriptParser::FunctionDeclarationContext::getRuleIndex() const {
  return StaticScriptParser::RuleFunctionDeclaration;
}


antlrcpp::Any StaticScriptParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::FunctionDeclarationContext* StaticScriptParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, StaticScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(StaticScriptParser::Function);
    setState(140);
    match(StaticScriptParser::Identifier);
    setState(141);
    match(StaticScriptParser::OpenParen);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StaticScriptParser::Identifier) {
      setState(142);
      parameterList();
    }
    setState(145);
    match(StaticScriptParser::CloseParen);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StaticScriptParser::Colon) {
      setState(146);
      typeAnnotation();
    }
    setState(149);
    functionBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

StaticScriptParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> StaticScriptParser::ParameterListContext::Identifier() {
  return getTokens(StaticScriptParser::Identifier);
}

tree::TerminalNode* StaticScriptParser::ParameterListContext::Identifier(size_t i) {
  return getToken(StaticScriptParser::Identifier, i);
}

std::vector<StaticScriptParser::TypeAnnotationContext *> StaticScriptParser::ParameterListContext::typeAnnotation() {
  return getRuleContexts<StaticScriptParser::TypeAnnotationContext>();
}

StaticScriptParser::TypeAnnotationContext* StaticScriptParser::ParameterListContext::typeAnnotation(size_t i) {
  return getRuleContext<StaticScriptParser::TypeAnnotationContext>(i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ParameterListContext::Comma() {
  return getTokens(StaticScriptParser::Comma);
}

tree::TerminalNode* StaticScriptParser::ParameterListContext::Comma(size_t i) {
  return getToken(StaticScriptParser::Comma, i);
}


size_t StaticScriptParser::ParameterListContext::getRuleIndex() const {
  return StaticScriptParser::RuleParameterList;
}


antlrcpp::Any StaticScriptParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ParameterListContext* StaticScriptParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 32, StaticScriptParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(StaticScriptParser::Identifier);
    setState(152);
    typeAnnotation();
    setState(158);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StaticScriptParser::Comma) {
      setState(153);
      match(StaticScriptParser::Comma);
      setState(154);
      match(StaticScriptParser::Identifier);
      setState(155);
      typeAnnotation();
      setState(160);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

StaticScriptParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::CompoundStatementContext* StaticScriptParser::FunctionBodyContext::compoundStatement() {
  return getRuleContext<StaticScriptParser::CompoundStatementContext>(0);
}


size_t StaticScriptParser::FunctionBodyContext::getRuleIndex() const {
  return StaticScriptParser::RuleFunctionBody;
}


antlrcpp::Any StaticScriptParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::FunctionBodyContext* StaticScriptParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 34, StaticScriptParser::RuleFunctionBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

StaticScriptParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::CompoundStatementContext::OpenBrace() {
  return getToken(StaticScriptParser::OpenBrace, 0);
}

tree::TerminalNode* StaticScriptParser::CompoundStatementContext::CloseBrace() {
  return getToken(StaticScriptParser::CloseBrace, 0);
}

StaticScriptParser::StatementsContext* StaticScriptParser::CompoundStatementContext::statements() {
  return getRuleContext<StaticScriptParser::StatementsContext>(0);
}


size_t StaticScriptParser::CompoundStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleCompoundStatement;
}


antlrcpp::Any StaticScriptParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::CompoundStatementContext* StaticScriptParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, StaticScriptParser::RuleCompoundStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(StaticScriptParser::OpenBrace);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StaticScriptParser::Let)
      | (1ULL << StaticScriptParser::Const)
      | (1ULL << StaticScriptParser::If)
      | (1ULL << StaticScriptParser::For)
      | (1ULL << StaticScriptParser::While)
      | (1ULL << StaticScriptParser::Break)
      | (1ULL << StaticScriptParser::Continue)
      | (1ULL << StaticScriptParser::Function)
      | (1ULL << StaticScriptParser::Return)
      | (1ULL << StaticScriptParser::OpenParen)
      | (1ULL << StaticScriptParser::OpenBracket)
      | (1ULL << StaticScriptParser::OpenBrace)
      | (1ULL << StaticScriptParser::SemiColon)
      | (1ULL << StaticScriptParser::PlusPlus)
      | (1ULL << StaticScriptParser::MinusMinus)
      | (1ULL << StaticScriptParser::Not)
      | (1ULL << StaticScriptParser::BitNot)
      | (1ULL << StaticScriptParser::Plus)
      | (1ULL << StaticScriptParser::Minus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (StaticScriptParser::BooleanLiteral - 64))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::FloatLiteral - 64))
      | (1ULL << (StaticScriptParser::StringLiteral - 64))
      | (1ULL << (StaticScriptParser::Identifier - 64)))) != 0)) {
      setState(164);
      statements();
    }
    setState(167);
    match(StaticScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

StaticScriptParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ExpressionStatementContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* StaticScriptParser::ExpressionStatementContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}


size_t StaticScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleExpressionStatement;
}


antlrcpp::Any StaticScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ExpressionStatementContext* StaticScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, StaticScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    expression(0);
    setState(170);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

StaticScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StaticScriptParser::ExpressionContext::getRuleIndex() const {
  return StaticScriptParser::RuleExpression;
}

void StaticScriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrefixUnaryExprContext ------------------------------------------------------------------

StaticScriptParser::ExpressionContext* StaticScriptParser::PrefixUnaryExprContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::Not() {
  return getToken(StaticScriptParser::Not, 0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::BitNot() {
  return getToken(StaticScriptParser::BitNot, 0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::Plus() {
  return getToken(StaticScriptParser::Plus, 0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::Minus() {
  return getToken(StaticScriptParser::Minus, 0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::PlusPlus() {
  return getToken(StaticScriptParser::PlusPlus, 0);
}

tree::TerminalNode* StaticScriptParser::PrefixUnaryExprContext::MinusMinus() {
  return getToken(StaticScriptParser::MinusMinus, 0);
}

StaticScriptParser::PrefixUnaryExprContext::PrefixUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::PrefixUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitPrefixUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

tree::TerminalNode* StaticScriptParser::IdentifierExprContext::Identifier() {
  return getToken(StaticScriptParser::Identifier, 0);
}

StaticScriptParser::IdentifierExprContext::IdentifierExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<StaticScriptParser::ExpressionContext *> StaticScriptParser::BinaryExprContext::expression() {
  return getRuleContexts<StaticScriptParser::ExpressionContext>();
}

StaticScriptParser::ExpressionContext* StaticScriptParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<StaticScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Multiply() {
  return getToken(StaticScriptParser::Multiply, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Divide() {
  return getToken(StaticScriptParser::Divide, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Modulus() {
  return getToken(StaticScriptParser::Modulus, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Plus() {
  return getToken(StaticScriptParser::Plus, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Minus() {
  return getToken(StaticScriptParser::Minus, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ShiftLeft() {
  return getToken(StaticScriptParser::ShiftLeft, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ArithmeticShiftRight() {
  return getToken(StaticScriptParser::ArithmeticShiftRight, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::LogicalShiftRight() {
  return getToken(StaticScriptParser::LogicalShiftRight, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::LessThan() {
  return getToken(StaticScriptParser::LessThan, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::GreaterThan() {
  return getToken(StaticScriptParser::GreaterThan, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::LessThanEquals() {
  return getToken(StaticScriptParser::LessThanEquals, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::GreaterThanEquals() {
  return getToken(StaticScriptParser::GreaterThanEquals, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Equals() {
  return getToken(StaticScriptParser::Equals, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::NotEquals() {
  return getToken(StaticScriptParser::NotEquals, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitAnd() {
  return getToken(StaticScriptParser::BitAnd, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitXOr() {
  return getToken(StaticScriptParser::BitXOr, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitOr() {
  return getToken(StaticScriptParser::BitOr, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::And() {
  return getToken(StaticScriptParser::And, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Or() {
  return getToken(StaticScriptParser::Or, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Nullish() {
  return getToken(StaticScriptParser::Nullish, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ConditionalQuestion() {
  return getToken(StaticScriptParser::ConditionalQuestion, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::Assign() {
  return getToken(StaticScriptParser::Assign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::PlusAssign() {
  return getToken(StaticScriptParser::PlusAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::MinusAssign() {
  return getToken(StaticScriptParser::MinusAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::MultiplyAssign() {
  return getToken(StaticScriptParser::MultiplyAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::DivideAssign() {
  return getToken(StaticScriptParser::DivideAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ModulusAssign() {
  return getToken(StaticScriptParser::ModulusAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ShiftLeftAssign() {
  return getToken(StaticScriptParser::ShiftLeftAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::ArithmeticShiftRightAssign() {
  return getToken(StaticScriptParser::ArithmeticShiftRightAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::LogicalShiftRightAssign() {
  return getToken(StaticScriptParser::LogicalShiftRightAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitAndAssign() {
  return getToken(StaticScriptParser::BitAndAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitXorAssign() {
  return getToken(StaticScriptParser::BitXorAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::BitOrAssign() {
  return getToken(StaticScriptParser::BitOrAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::AndAssign() {
  return getToken(StaticScriptParser::AndAssign, 0);
}

tree::TerminalNode* StaticScriptParser::BinaryExprContext::OrAssign() {
  return getToken(StaticScriptParser::OrAssign, 0);
}

StaticScriptParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArraySubscriptExprContext ------------------------------------------------------------------

std::vector<StaticScriptParser::ExpressionContext *> StaticScriptParser::ArraySubscriptExprContext::expression() {
  return getRuleContexts<StaticScriptParser::ExpressionContext>();
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ArraySubscriptExprContext::expression(size_t i) {
  return getRuleContext<StaticScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ArraySubscriptExprContext::OpenBracket() {
  return getTokens(StaticScriptParser::OpenBracket);
}

tree::TerminalNode* StaticScriptParser::ArraySubscriptExprContext::OpenBracket(size_t i) {
  return getToken(StaticScriptParser::OpenBracket, i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ArraySubscriptExprContext::CloseBracket() {
  return getTokens(StaticScriptParser::CloseBracket);
}

tree::TerminalNode* StaticScriptParser::ArraySubscriptExprContext::CloseBracket(size_t i) {
  return getToken(StaticScriptParser::CloseBracket, i);
}

StaticScriptParser::ArraySubscriptExprContext::ArraySubscriptExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::ArraySubscriptExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitArraySubscriptExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

StaticScriptParser::LiteralContext* StaticScriptParser::LiteralExprContext::literal() {
  return getRuleContext<StaticScriptParser::LiteralContext>(0);
}

StaticScriptParser::LiteralExprContext::LiteralExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::LiteralExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

StaticScriptParser::CallExpressionContext* StaticScriptParser::CallExprContext::callExpression() {
  return getRuleContext<StaticScriptParser::CallExpressionContext>(0);
}

StaticScriptParser::CallExprContext::CallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostfixUnaryExprContext ------------------------------------------------------------------

StaticScriptParser::ExpressionContext* StaticScriptParser::PostfixUnaryExprContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* StaticScriptParser::PostfixUnaryExprContext::PlusPlus() {
  return getToken(StaticScriptParser::PlusPlus, 0);
}

tree::TerminalNode* StaticScriptParser::PostfixUnaryExprContext::MinusMinus() {
  return getToken(StaticScriptParser::MinusMinus, 0);
}

StaticScriptParser::PostfixUnaryExprContext::PostfixUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::PostfixUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitPostfixUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* StaticScriptParser::ParenExprContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ParenExprContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* StaticScriptParser::ParenExprContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExprContext ------------------------------------------------------------------

std::vector<StaticScriptParser::ExpressionContext *> StaticScriptParser::TernaryExprContext::expression() {
  return getRuleContexts<StaticScriptParser::ExpressionContext>();
}

StaticScriptParser::ExpressionContext* StaticScriptParser::TernaryExprContext::expression(size_t i) {
  return getRuleContext<StaticScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* StaticScriptParser::TernaryExprContext::ConditionalQuestion() {
  return getToken(StaticScriptParser::ConditionalQuestion, 0);
}

tree::TerminalNode* StaticScriptParser::TernaryExprContext::Colon() {
  return getToken(StaticScriptParser::Colon, 0);
}

StaticScriptParser::TernaryExprContext::TernaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any StaticScriptParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::expression() {
   return expression(0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  StaticScriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  StaticScriptParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, StaticScriptParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(173);
      callExpression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PrefixUnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(174);
      dynamic_cast<PrefixUnaryExprContext *>(_localctx)->uop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << StaticScriptParser::PlusPlus)
        | (1ULL << StaticScriptParser::MinusMinus)
        | (1ULL << StaticScriptParser::Not)
        | (1ULL << StaticScriptParser::BitNot)
        | (1ULL << StaticScriptParser::Plus)
        | (1ULL << StaticScriptParser::Minus))) != 0))) {
        dynamic_cast<PrefixUnaryExprContext *>(_localctx)->uop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(175);
      expression(18);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(176);
      match(StaticScriptParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<LiteralExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(177);
      literal();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(178);
      match(StaticScriptParser::OpenParen);
      setState(179);
      expression(0);
      setState(180);
      match(StaticScriptParser::CloseParen);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(240);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(184);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(185);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << StaticScriptParser::Multiply)
            | (1ULL << StaticScriptParser::Divide)
            | (1ULL << StaticScriptParser::Modulus))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(186);
          expression(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(187);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(188);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == StaticScriptParser::Plus

          || _la == StaticScriptParser::Minus)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(189);
          expression(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(190);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(191);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << StaticScriptParser::ShiftLeft)
            | (1ULL << StaticScriptParser::ArithmeticShiftRight)
            | (1ULL << StaticScriptParser::LogicalShiftRight))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(192);
          expression(16);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(193);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(194);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << StaticScriptParser::LessThan)
            | (1ULL << StaticScriptParser::GreaterThan)
            | (1ULL << StaticScriptParser::LessThanEquals)
            | (1ULL << StaticScriptParser::GreaterThanEquals))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(195);
          expression(15);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(196);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(197);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == StaticScriptParser::Equals

          || _la == StaticScriptParser::NotEquals)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(198);
          expression(14);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(199);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(200);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::BitAnd);
          setState(201);
          expression(13);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(202);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(203);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::BitXOr);
          setState(204);
          expression(12);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(205);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(206);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::BitOr);
          setState(207);
          expression(11);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(208);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(209);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::And);
          setState(210);
          expression(10);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(212);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::Or);
          setState(213);
          expression(9);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(215);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::Nullish);
          setState(216);
          expression(8);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<TernaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(218);
          match(StaticScriptParser::ConditionalQuestion);
          setState(219);
          dynamic_cast<TernaryExprContext *>(_localctx)->trueExpr = expression(0);
          setState(220);
          match(StaticScriptParser::Colon);
          setState(221);
          dynamic_cast<TernaryExprContext *>(_localctx)->falseExpr = expression(7);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(223);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(224);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = match(StaticScriptParser::ConditionalQuestion);
          setState(225);
          expression(6);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(226);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(227);
          dynamic_cast<BinaryExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << StaticScriptParser::Assign)
            | (1ULL << StaticScriptParser::PlusAssign)
            | (1ULL << StaticScriptParser::MinusAssign)
            | (1ULL << StaticScriptParser::MultiplyAssign)
            | (1ULL << StaticScriptParser::DivideAssign)
            | (1ULL << StaticScriptParser::ModulusAssign)
            | (1ULL << StaticScriptParser::BitAndAssign)
            | (1ULL << StaticScriptParser::BitXorAssign)
            | (1ULL << StaticScriptParser::BitOrAssign)
            | (1ULL << StaticScriptParser::ShiftLeftAssign)
            | (1ULL << StaticScriptParser::ArithmeticShiftRightAssign)
            | (1ULL << StaticScriptParser::LogicalShiftRightAssign)
            | (1ULL << StaticScriptParser::AndAssign)
            | (1ULL << StaticScriptParser::OrAssign))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(228);
          expression(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ArraySubscriptExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->base = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(229);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(234); 
          _errHandler->sync(this);
          alt = 1;
          do {
            switch (alt) {
              case 1: {
                    setState(230);
                    match(StaticScriptParser::OpenBracket);
                    setState(231);
                    dynamic_cast<ArraySubscriptExprContext *>(_localctx)->expressionContext = expression(0);
                    dynamic_cast<ArraySubscriptExprContext *>(_localctx)->index.push_back(dynamic_cast<ArraySubscriptExprContext *>(_localctx)->expressionContext);
                    setState(232);
                    match(StaticScriptParser::CloseBracket);
                    break;
                  }

            default:
              throw NoViableAltException(this);
            }
            setState(236); 
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
          } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<PostfixUnaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(238);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(239);
          dynamic_cast<PostfixUnaryExprContext *>(_localctx)->uop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == StaticScriptParser::PlusPlus

          || _la == StaticScriptParser::MinusMinus)) {
            dynamic_cast<PostfixUnaryExprContext *>(_localctx)->uop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CallExpressionContext ------------------------------------------------------------------

StaticScriptParser::CallExpressionContext::CallExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::CallExpressionContext::Identifier() {
  return getToken(StaticScriptParser::Identifier, 0);
}

tree::TerminalNode* StaticScriptParser::CallExpressionContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

tree::TerminalNode* StaticScriptParser::CallExpressionContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::ArgumentListContext* StaticScriptParser::CallExpressionContext::argumentList() {
  return getRuleContext<StaticScriptParser::ArgumentListContext>(0);
}


size_t StaticScriptParser::CallExpressionContext::getRuleIndex() const {
  return StaticScriptParser::RuleCallExpression;
}


antlrcpp::Any StaticScriptParser::CallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitCallExpression(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::CallExpressionContext* StaticScriptParser::callExpression() {
  CallExpressionContext *_localctx = _tracker.createInstance<CallExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, StaticScriptParser::RuleCallExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(StaticScriptParser::Identifier);
    setState(246);
    match(StaticScriptParser::OpenParen);
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (StaticScriptParser::OpenParen - 15))
      | (1ULL << (StaticScriptParser::OpenBracket - 15))
      | (1ULL << (StaticScriptParser::PlusPlus - 15))
      | (1ULL << (StaticScriptParser::MinusMinus - 15))
      | (1ULL << (StaticScriptParser::Not - 15))
      | (1ULL << (StaticScriptParser::BitNot - 15))
      | (1ULL << (StaticScriptParser::Plus - 15))
      | (1ULL << (StaticScriptParser::Minus - 15))
      | (1ULL << (StaticScriptParser::BooleanLiteral - 15))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::FloatLiteral - 15))
      | (1ULL << (StaticScriptParser::StringLiteral - 15))
      | (1ULL << (StaticScriptParser::Identifier - 15)))) != 0)) {
      setState(247);
      argumentList();
    }
    setState(250);
    match(StaticScriptParser::CloseParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

StaticScriptParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::ExpressionListContext* StaticScriptParser::ArgumentListContext::expressionList() {
  return getRuleContext<StaticScriptParser::ExpressionListContext>(0);
}


size_t StaticScriptParser::ArgumentListContext::getRuleIndex() const {
  return StaticScriptParser::RuleArgumentList;
}


antlrcpp::Any StaticScriptParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ArgumentListContext* StaticScriptParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 44, StaticScriptParser::RuleArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

StaticScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::LiteralContext::BooleanLiteral() {
  return getToken(StaticScriptParser::BooleanLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::DecimalIntegerLiteral() {
  return getToken(StaticScriptParser::DecimalIntegerLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::HexIntegerLiteral() {
  return getToken(StaticScriptParser::HexIntegerLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::OctalIntegerLiteral() {
  return getToken(StaticScriptParser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::BinaryIntegerLiteral() {
  return getToken(StaticScriptParser::BinaryIntegerLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::FloatLiteral() {
  return getToken(StaticScriptParser::FloatLiteral, 0);
}

tree::TerminalNode* StaticScriptParser::LiteralContext::StringLiteral() {
  return getToken(StaticScriptParser::StringLiteral, 0);
}

StaticScriptParser::ArrayLiteralContext* StaticScriptParser::LiteralContext::arrayLiteral() {
  return getRuleContext<StaticScriptParser::ArrayLiteralContext>(0);
}


size_t StaticScriptParser::LiteralContext::getRuleIndex() const {
  return StaticScriptParser::RuleLiteral;
}


antlrcpp::Any StaticScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::LiteralContext* StaticScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 46, StaticScriptParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(254);
        match(StaticScriptParser::BooleanLiteral);
        break;
      }

      case StaticScriptParser::DecimalIntegerLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(255);
        match(StaticScriptParser::DecimalIntegerLiteral);
        break;
      }

      case StaticScriptParser::HexIntegerLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(256);
        match(StaticScriptParser::HexIntegerLiteral);
        break;
      }

      case StaticScriptParser::OctalIntegerLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(257);
        match(StaticScriptParser::OctalIntegerLiteral);
        break;
      }

      case StaticScriptParser::BinaryIntegerLiteral: {
        enterOuterAlt(_localctx, 5);
        setState(258);
        match(StaticScriptParser::BinaryIntegerLiteral);
        break;
      }

      case StaticScriptParser::FloatLiteral: {
        enterOuterAlt(_localctx, 6);
        setState(259);
        match(StaticScriptParser::FloatLiteral);
        break;
      }

      case StaticScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 7);
        setState(260);
        match(StaticScriptParser::StringLiteral);
        break;
      }

      case StaticScriptParser::OpenBracket: {
        enterOuterAlt(_localctx, 8);
        setState(261);
        arrayLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

StaticScriptParser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::ArrayLiteralContext::OpenBracket() {
  return getToken(StaticScriptParser::OpenBracket, 0);
}

tree::TerminalNode* StaticScriptParser::ArrayLiteralContext::CloseBracket() {
  return getToken(StaticScriptParser::CloseBracket, 0);
}

StaticScriptParser::ExpressionListContext* StaticScriptParser::ArrayLiteralContext::expressionList() {
  return getRuleContext<StaticScriptParser::ExpressionListContext>(0);
}


size_t StaticScriptParser::ArrayLiteralContext::getRuleIndex() const {
  return StaticScriptParser::RuleArrayLiteral;
}


antlrcpp::Any StaticScriptParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ArrayLiteralContext* StaticScriptParser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 48, StaticScriptParser::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(StaticScriptParser::OpenBracket);
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (StaticScriptParser::OpenParen - 15))
      | (1ULL << (StaticScriptParser::OpenBracket - 15))
      | (1ULL << (StaticScriptParser::PlusPlus - 15))
      | (1ULL << (StaticScriptParser::MinusMinus - 15))
      | (1ULL << (StaticScriptParser::Not - 15))
      | (1ULL << (StaticScriptParser::BitNot - 15))
      | (1ULL << (StaticScriptParser::Plus - 15))
      | (1ULL << (StaticScriptParser::Minus - 15))
      | (1ULL << (StaticScriptParser::BooleanLiteral - 15))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::FloatLiteral - 15))
      | (1ULL << (StaticScriptParser::StringLiteral - 15))
      | (1ULL << (StaticScriptParser::Identifier - 15)))) != 0)) {
      setState(265);
      expressionList();
    }
    setState(268);
    match(StaticScriptParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

StaticScriptParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StaticScriptParser::ExpressionContext *> StaticScriptParser::ExpressionListContext::expression() {
  return getRuleContexts<StaticScriptParser::ExpressionContext>();
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<StaticScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ExpressionListContext::Comma() {
  return getTokens(StaticScriptParser::Comma);
}

tree::TerminalNode* StaticScriptParser::ExpressionListContext::Comma(size_t i) {
  return getToken(StaticScriptParser::Comma, i);
}


size_t StaticScriptParser::ExpressionListContext::getRuleIndex() const {
  return StaticScriptParser::RuleExpressionList;
}


antlrcpp::Any StaticScriptParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ExpressionListContext* StaticScriptParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 50, StaticScriptParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    expression(0);
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StaticScriptParser::Comma) {
      setState(271);
      match(StaticScriptParser::Comma);
      setState(272);
      expression(0);
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

StaticScriptParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::IfStatementContext* StaticScriptParser::SelectionStatementContext::ifStatement() {
  return getRuleContext<StaticScriptParser::IfStatementContext>(0);
}


size_t StaticScriptParser::SelectionStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleSelectionStatement;
}


antlrcpp::Any StaticScriptParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::SelectionStatementContext* StaticScriptParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, StaticScriptParser::RuleSelectionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    ifStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

StaticScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::IfStatementContext::If() {
  return getToken(StaticScriptParser::If, 0);
}

tree::TerminalNode* StaticScriptParser::IfStatementContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

tree::TerminalNode* StaticScriptParser::IfStatementContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::IfStatementContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

std::vector<StaticScriptParser::StatementContext *> StaticScriptParser::IfStatementContext::statement() {
  return getRuleContexts<StaticScriptParser::StatementContext>();
}

StaticScriptParser::StatementContext* StaticScriptParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<StaticScriptParser::StatementContext>(i);
}

tree::TerminalNode* StaticScriptParser::IfStatementContext::Else() {
  return getToken(StaticScriptParser::Else, 0);
}


size_t StaticScriptParser::IfStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleIfStatement;
}


antlrcpp::Any StaticScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::IfStatementContext* StaticScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, StaticScriptParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(StaticScriptParser::If);
    setState(281);
    match(StaticScriptParser::OpenParen);
    setState(282);
    dynamic_cast<IfStatementContext *>(_localctx)->ifCondition = expression(0);
    setState(283);
    match(StaticScriptParser::CloseParen);
    setState(284);
    dynamic_cast<IfStatementContext *>(_localctx)->thenBody = statement();
    setState(287);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(285);
      match(StaticScriptParser::Else);
      setState(286);
      dynamic_cast<IfStatementContext *>(_localctx)->elseBody = statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

StaticScriptParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::WhileStatementContext* StaticScriptParser::IterationStatementContext::whileStatement() {
  return getRuleContext<StaticScriptParser::WhileStatementContext>(0);
}

StaticScriptParser::ForStatementContext* StaticScriptParser::IterationStatementContext::forStatement() {
  return getRuleContext<StaticScriptParser::ForStatementContext>(0);
}


size_t StaticScriptParser::IterationStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleIterationStatement;
}


antlrcpp::Any StaticScriptParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::IterationStatementContext* StaticScriptParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, StaticScriptParser::RuleIterationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(289);
        whileStatement();
        break;
      }

      case StaticScriptParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(290);
        forStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

StaticScriptParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::WhileStatementContext::While() {
  return getToken(StaticScriptParser::While, 0);
}

tree::TerminalNode* StaticScriptParser::WhileStatementContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

tree::TerminalNode* StaticScriptParser::WhileStatementContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::WhileStatementContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

StaticScriptParser::StatementContext* StaticScriptParser::WhileStatementContext::statement() {
  return getRuleContext<StaticScriptParser::StatementContext>(0);
}


size_t StaticScriptParser::WhileStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleWhileStatement;
}


antlrcpp::Any StaticScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::WhileStatementContext* StaticScriptParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, StaticScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(StaticScriptParser::While);
    setState(294);
    match(StaticScriptParser::OpenParen);
    setState(295);
    dynamic_cast<WhileStatementContext *>(_localctx)->whileCondition = expression(0);
    setState(296);
    match(StaticScriptParser::CloseParen);
    setState(297);
    dynamic_cast<WhileStatementContext *>(_localctx)->whileBody = statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

StaticScriptParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::ForStatementContext::For() {
  return getToken(StaticScriptParser::For, 0);
}

tree::TerminalNode* StaticScriptParser::ForStatementContext::OpenParen() {
  return getToken(StaticScriptParser::OpenParen, 0);
}

std::vector<tree::TerminalNode *> StaticScriptParser::ForStatementContext::SemiColon() {
  return getTokens(StaticScriptParser::SemiColon);
}

tree::TerminalNode* StaticScriptParser::ForStatementContext::SemiColon(size_t i) {
  return getToken(StaticScriptParser::SemiColon, i);
}

tree::TerminalNode* StaticScriptParser::ForStatementContext::CloseParen() {
  return getToken(StaticScriptParser::CloseParen, 0);
}

StaticScriptParser::StatementContext* StaticScriptParser::ForStatementContext::statement() {
  return getRuleContext<StaticScriptParser::StatementContext>(0);
}

StaticScriptParser::ForInitContext* StaticScriptParser::ForStatementContext::forInit() {
  return getRuleContext<StaticScriptParser::ForInitContext>(0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ForStatementContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}

StaticScriptParser::ExpressionListContext* StaticScriptParser::ForStatementContext::expressionList() {
  return getRuleContext<StaticScriptParser::ExpressionListContext>(0);
}


size_t StaticScriptParser::ForStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleForStatement;
}


antlrcpp::Any StaticScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ForStatementContext* StaticScriptParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, StaticScriptParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(StaticScriptParser::For);
    setState(300);
    match(StaticScriptParser::OpenParen);
    setState(302);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StaticScriptParser::Let)
      | (1ULL << StaticScriptParser::Const)
      | (1ULL << StaticScriptParser::OpenParen)
      | (1ULL << StaticScriptParser::OpenBracket)
      | (1ULL << StaticScriptParser::PlusPlus)
      | (1ULL << StaticScriptParser::MinusMinus)
      | (1ULL << StaticScriptParser::Not)
      | (1ULL << StaticScriptParser::BitNot)
      | (1ULL << StaticScriptParser::Plus)
      | (1ULL << StaticScriptParser::Minus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (StaticScriptParser::BooleanLiteral - 64))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 64))
      | (1ULL << (StaticScriptParser::FloatLiteral - 64))
      | (1ULL << (StaticScriptParser::StringLiteral - 64))
      | (1ULL << (StaticScriptParser::Identifier - 64)))) != 0)) {
      setState(301);
      forInit();
    }
    setState(304);
    match(StaticScriptParser::SemiColon);
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (StaticScriptParser::OpenParen - 15))
      | (1ULL << (StaticScriptParser::OpenBracket - 15))
      | (1ULL << (StaticScriptParser::PlusPlus - 15))
      | (1ULL << (StaticScriptParser::MinusMinus - 15))
      | (1ULL << (StaticScriptParser::Not - 15))
      | (1ULL << (StaticScriptParser::BitNot - 15))
      | (1ULL << (StaticScriptParser::Plus - 15))
      | (1ULL << (StaticScriptParser::Minus - 15))
      | (1ULL << (StaticScriptParser::BooleanLiteral - 15))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::FloatLiteral - 15))
      | (1ULL << (StaticScriptParser::StringLiteral - 15))
      | (1ULL << (StaticScriptParser::Identifier - 15)))) != 0)) {
      setState(305);
      dynamic_cast<ForStatementContext *>(_localctx)->forCondition = expression(0);
    }
    setState(308);
    match(StaticScriptParser::SemiColon);
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (StaticScriptParser::OpenParen - 15))
      | (1ULL << (StaticScriptParser::OpenBracket - 15))
      | (1ULL << (StaticScriptParser::PlusPlus - 15))
      | (1ULL << (StaticScriptParser::MinusMinus - 15))
      | (1ULL << (StaticScriptParser::Not - 15))
      | (1ULL << (StaticScriptParser::BitNot - 15))
      | (1ULL << (StaticScriptParser::Plus - 15))
      | (1ULL << (StaticScriptParser::Minus - 15))
      | (1ULL << (StaticScriptParser::BooleanLiteral - 15))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::FloatLiteral - 15))
      | (1ULL << (StaticScriptParser::StringLiteral - 15))
      | (1ULL << (StaticScriptParser::Identifier - 15)))) != 0)) {
      setState(309);
      dynamic_cast<ForStatementContext *>(_localctx)->forUpdate = expressionList();
    }
    setState(312);
    match(StaticScriptParser::CloseParen);
    setState(313);
    dynamic_cast<ForStatementContext *>(_localctx)->forBody = statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

StaticScriptParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::VariableDeclaratorsContext* StaticScriptParser::ForInitContext::variableDeclarators() {
  return getRuleContext<StaticScriptParser::VariableDeclaratorsContext>(0);
}

StaticScriptParser::ExpressionListContext* StaticScriptParser::ForInitContext::expressionList() {
  return getRuleContext<StaticScriptParser::ExpressionListContext>(0);
}


size_t StaticScriptParser::ForInitContext::getRuleIndex() const {
  return StaticScriptParser::RuleForInit;
}


antlrcpp::Any StaticScriptParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ForInitContext* StaticScriptParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 62, StaticScriptParser::RuleForInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::Let:
      case StaticScriptParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(315);
        variableDeclarators();
        break;
      }

      case StaticScriptParser::OpenParen:
      case StaticScriptParser::OpenBracket:
      case StaticScriptParser::PlusPlus:
      case StaticScriptParser::MinusMinus:
      case StaticScriptParser::Not:
      case StaticScriptParser::BitNot:
      case StaticScriptParser::Plus:
      case StaticScriptParser::Minus:
      case StaticScriptParser::BooleanLiteral:
      case StaticScriptParser::DecimalIntegerLiteral:
      case StaticScriptParser::HexIntegerLiteral:
      case StaticScriptParser::OctalIntegerLiteral:
      case StaticScriptParser::BinaryIntegerLiteral:
      case StaticScriptParser::FloatLiteral:
      case StaticScriptParser::StringLiteral:
      case StaticScriptParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(316);
        expressionList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

StaticScriptParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StaticScriptParser::ContinueStatementContext* StaticScriptParser::JumpStatementContext::continueStatement() {
  return getRuleContext<StaticScriptParser::ContinueStatementContext>(0);
}

StaticScriptParser::BreakStatementContext* StaticScriptParser::JumpStatementContext::breakStatement() {
  return getRuleContext<StaticScriptParser::BreakStatementContext>(0);
}

StaticScriptParser::ReturnStatementContext* StaticScriptParser::JumpStatementContext::returnStatement() {
  return getRuleContext<StaticScriptParser::ReturnStatementContext>(0);
}


size_t StaticScriptParser::JumpStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleJumpStatement;
}


antlrcpp::Any StaticScriptParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::JumpStatementContext* StaticScriptParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, StaticScriptParser::RuleJumpStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StaticScriptParser::Continue: {
        enterOuterAlt(_localctx, 1);
        setState(319);
        continueStatement();
        break;
      }

      case StaticScriptParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(320);
        breakStatement();
        break;
      }

      case StaticScriptParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(321);
        returnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

StaticScriptParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::ContinueStatementContext::Continue() {
  return getToken(StaticScriptParser::Continue, 0);
}

tree::TerminalNode* StaticScriptParser::ContinueStatementContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}


size_t StaticScriptParser::ContinueStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleContinueStatement;
}


antlrcpp::Any StaticScriptParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ContinueStatementContext* StaticScriptParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, StaticScriptParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(StaticScriptParser::Continue);
    setState(325);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

StaticScriptParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::BreakStatementContext::Break() {
  return getToken(StaticScriptParser::Break, 0);
}

tree::TerminalNode* StaticScriptParser::BreakStatementContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}


size_t StaticScriptParser::BreakStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleBreakStatement;
}


antlrcpp::Any StaticScriptParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::BreakStatementContext* StaticScriptParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, StaticScriptParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(StaticScriptParser::Break);
    setState(328);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

StaticScriptParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StaticScriptParser::ReturnStatementContext::Return() {
  return getToken(StaticScriptParser::Return, 0);
}

tree::TerminalNode* StaticScriptParser::ReturnStatementContext::SemiColon() {
  return getToken(StaticScriptParser::SemiColon, 0);
}

StaticScriptParser::ExpressionContext* StaticScriptParser::ReturnStatementContext::expression() {
  return getRuleContext<StaticScriptParser::ExpressionContext>(0);
}


size_t StaticScriptParser::ReturnStatementContext::getRuleIndex() const {
  return StaticScriptParser::RuleReturnStatement;
}


antlrcpp::Any StaticScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StaticScriptParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

StaticScriptParser::ReturnStatementContext* StaticScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, StaticScriptParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(StaticScriptParser::Return);
    setState(332);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (StaticScriptParser::OpenParen - 15))
      | (1ULL << (StaticScriptParser::OpenBracket - 15))
      | (1ULL << (StaticScriptParser::PlusPlus - 15))
      | (1ULL << (StaticScriptParser::MinusMinus - 15))
      | (1ULL << (StaticScriptParser::Not - 15))
      | (1ULL << (StaticScriptParser::BitNot - 15))
      | (1ULL << (StaticScriptParser::Plus - 15))
      | (1ULL << (StaticScriptParser::Minus - 15))
      | (1ULL << (StaticScriptParser::BooleanLiteral - 15))
      | (1ULL << (StaticScriptParser::DecimalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::HexIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::OctalIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::BinaryIntegerLiteral - 15))
      | (1ULL << (StaticScriptParser::FloatLiteral - 15))
      | (1ULL << (StaticScriptParser::StringLiteral - 15))
      | (1ULL << (StaticScriptParser::Identifier - 15)))) != 0)) {
      setState(331);
      dynamic_cast<ReturnStatementContext *>(_localctx)->returnExpr = expression(0);
    }
    setState(334);
    match(StaticScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool StaticScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 20: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool StaticScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);
    case 6: return precpred(_ctx, 11);
    case 7: return precpred(_ctx, 10);
    case 8: return precpred(_ctx, 9);
    case 9: return precpred(_ctx, 8);
    case 10: return precpred(_ctx, 7);
    case 11: return precpred(_ctx, 6);
    case 12: return precpred(_ctx, 5);
    case 13: return precpred(_ctx, 4);
    case 14: return precpred(_ctx, 21);
    case 15: return precpred(_ctx, 19);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> StaticScriptParser::_decisionToDFA;
atn::PredictionContextCache StaticScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN StaticScriptParser::_atn;
std::vector<uint16_t> StaticScriptParser::_serializedATN;

std::vector<std::string> StaticScriptParser::_ruleNames = {
  "module", "statements", "statement", "emptyStatement", "declarationStatement", 
  "declaration", "variableDeclaration", "variableDeclarators", "variableModifier", 
  "variableDeclarator", "variableInitializer", "typeAnnotation", "type", 
  "arrayType", "basicType", "functionDeclaration", "parameterList", "functionBody", 
  "compoundStatement", "expressionStatement", "expression", "callExpression", 
  "argumentList", "literal", "arrayLiteral", "expressionList", "selectionStatement", 
  "ifStatement", "iterationStatement", "whileStatement", "forStatement", 
  "forInit", "jumpStatement", "continueStatement", "breakStatement", "returnStatement"
};

std::vector<std::string> StaticScriptParser::_literalNames = {
  "", "'boolean'", "'int'", "'number'", "'string'", "'let'", "'const'", 
  "'if'", "'else'", "'for'", "'while'", "'break'", "'continue'", "'function'", 
  "'return'", "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','", 
  "'++'", "'--'", "'!'", "'~'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", 
  "'^'", "'|'", "'<<'", "'>>'", "'>>>'", "'<'", "'>'", "'<='", "'>='", "'=='", 
  "'!='", "'&&'", "'||'", "'\u003F\u003F'", "'\u003F'", "'='", "'+='", "'-='", 
  "'*='", "'/='", "'%='", "'&='", "'^='", "'|='", "'<<='", "'>>='", "'>>>='", 
  "'&&='", "'||='", "'null'"
};

std::vector<std::string> StaticScriptParser::_symbolicNames = {
  "", "Boolean", "Integer", "Number", "String", "Let", "Const", "If", "Else", 
  "For", "While", "Break", "Continue", "Function", "Return", "OpenParen", 
  "CloseParen", "OpenBracket", "CloseBracket", "OpenBrace", "CloseBrace", 
  "Colon", "SemiColon", "Comma", "PlusPlus", "MinusMinus", "Not", "BitNot", 
  "Plus", "Minus", "Multiply", "Divide", "Modulus", "BitAnd", "BitXOr", 
  "BitOr", "ShiftLeft", "ArithmeticShiftRight", "LogicalShiftRight", "LessThan", 
  "GreaterThan", "LessThanEquals", "GreaterThanEquals", "Equals", "NotEquals", 
  "And", "Or", "Nullish", "ConditionalQuestion", "Assign", "PlusAssign", 
  "MinusAssign", "MultiplyAssign", "DivideAssign", "ModulusAssign", "BitAndAssign", 
  "BitXorAssign", "BitOrAssign", "ShiftLeftAssign", "ArithmeticShiftRightAssign", 
  "LogicalShiftRightAssign", "AndAssign", "OrAssign", "NullLiteral", "BooleanLiteral", 
  "DecimalIntegerLiteral", "HexIntegerLiteral", "OctalIntegerLiteral", "BinaryIntegerLiteral", 
  "FloatLiteral", "StringLiteral", "WhiteSpaces", "LineTerminator", "Identifier", 
  "MultiLineComment", "SingleLineComment", "UnexpectedCharacter"
};

dfa::Vocabulary StaticScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> StaticScriptParser::_tokenNames;

StaticScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x4e, 0x153, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x3, 0x2, 
       0x5, 0x2, 0x4c, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 
       0x51, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x52, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5c, 0xa, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x5, 0x7, 0x64, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x6d, 0xa, 0x9, 0xc, 0x9, 
       0xe, 0x9, 0x70, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x5, 0xb, 0x76, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x79, 0xa, 0xb, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x5, 0xe, 0x83, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x6, 0xf, 0x88, 0xa, 0xf, 0xd, 0xf, 0xe, 0xf, 0x89, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x92, 
       0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x96, 0xa, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x7, 0x12, 0x9f, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xa2, 0xb, 
       0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xa8, 
       0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xb9, 0xa, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 0xed, 0xa, 0x16, 0xd, 0x16, 
       0xe, 0x16, 0xee, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xf3, 0xa, 0x16, 
       0xc, 0x16, 0xe, 0x16, 0xf6, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x5, 0x17, 0xfb, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x109, 0xa, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x10d, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x114, 0xa, 0x1b, 0xc, 
       0x1b, 0xe, 0x1b, 0x117, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x5, 0x1d, 0x122, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x126, 
       0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x131, 0xa, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x135, 0xa, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x5, 0x20, 0x139, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x140, 0xa, 0x21, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x145, 0xa, 0x22, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
       0x25, 0x5, 0x25, 0x14f, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x2, 0x3, 0x2a, 0x26, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
       0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
       0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
       0x40, 0x42, 0x44, 0x46, 0x48, 0x2, 0xc, 0x3, 0x2, 0x7, 0x8, 0x3, 
       0x2, 0x3, 0x6, 0x3, 0x2, 0x1a, 0x1f, 0x3, 0x2, 0x20, 0x22, 0x3, 0x2, 
       0x1e, 0x1f, 0x3, 0x2, 0x26, 0x28, 0x3, 0x2, 0x29, 0x2c, 0x3, 0x2, 
       0x2d, 0x2e, 0x3, 0x2, 0x33, 0x40, 0x3, 0x2, 0x1a, 0x1b, 0x2, 0x168, 
       0x2, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x50, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x63, 0x3, 0x2, 0x2, 0x2, 0xe, 0x65, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0x68, 0x3, 0x2, 0x2, 0x2, 0x12, 0x71, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x73, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7a, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x82, 0x3, 0x2, 0x2, 0x2, 
       0x1c, 0x84, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x20, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x22, 0x99, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa3, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x28, 0xab, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xf7, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x30, 0x108, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x34, 0x110, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x118, 0x3, 0x2, 0x2, 0x2, 0x38, 0x11a, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x125, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x127, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x13f, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x144, 0x3, 0x2, 0x2, 0x2, 0x44, 0x146, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x149, 0x3, 0x2, 0x2, 0x2, 0x48, 0x14c, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 
       0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 
       0x4d, 0x4e, 0x7, 0x2, 0x2, 0x3, 0x4e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x4f, 
       0x51, 0x5, 0x6, 0x4, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
       0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 
       0x2, 0x2, 0x2, 0x53, 0x5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x5c, 0x5, 0x8, 
       0x5, 0x2, 0x55, 0x5c, 0x5, 0xa, 0x6, 0x2, 0x56, 0x5c, 0x5, 0x26, 
       0x14, 0x2, 0x57, 0x5c, 0x5, 0x28, 0x15, 0x2, 0x58, 0x5c, 0x5, 0x36, 
       0x1c, 0x2, 0x59, 0x5c, 0x5, 0x3a, 0x1e, 0x2, 0x5a, 0x5c, 0x5, 0x42, 
       0x22, 0x2, 0x5b, 0x54, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x55, 0x3, 0x2, 
       0x2, 0x2, 0x5b, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x57, 0x3, 0x2, 0x2, 
       0x2, 0x5b, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 
       0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5d, 
       0x5e, 0x7, 0x18, 0x2, 0x2, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
       0x5, 0xc, 0x7, 0x2, 0x60, 0xb, 0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x5, 
       0xe, 0x8, 0x2, 0x62, 0x64, 0x5, 0x20, 0x11, 0x2, 0x63, 0x61, 0x3, 
       0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x65, 0x66, 0x5, 0x10, 0x9, 0x2, 0x66, 0x67, 0x7, 0x18, 
       0x2, 0x2, 0x67, 0xf, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x5, 0x12, 0xa, 
       0x2, 0x69, 0x6e, 0x5, 0x14, 0xb, 0x2, 0x6a, 0x6b, 0x7, 0x19, 0x2, 
       0x2, 0x6b, 0x6d, 0x5, 0x14, 0xb, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 
       0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 
       0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x70, 
       0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x9, 0x2, 0x2, 0x2, 0x72, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x7, 0x4b, 0x2, 0x2, 0x74, 0x76, 
       0x5, 0x18, 0xd, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
       0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x5, 
       0x16, 0xc, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 
       0x2, 0x2, 0x2, 0x79, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x33, 
       0x2, 0x2, 0x7b, 0x7c, 0x5, 0x2a, 0x16, 0x2, 0x7c, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0x7d, 0x7e, 0x7, 0x17, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x1a, 
       0xe, 0x2, 0x7f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x5, 0x1c, 
       0xf, 0x2, 0x81, 0x83, 0x5, 0x1e, 0x10, 0x2, 0x82, 0x80, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0x84, 0x87, 0x5, 0x1e, 0x10, 0x2, 0x85, 0x86, 0x7, 0x13, 0x2, 
       0x2, 0x86, 0x88, 0x7, 0x14, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 
       0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 
       0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8b, 
       0x8c, 0x9, 0x3, 0x2, 0x2, 0x8c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 
       0x7, 0xf, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x4b, 0x2, 0x2, 0x8f, 0x91, 
       0x7, 0x11, 0x2, 0x2, 0x90, 0x92, 0x5, 0x22, 0x12, 0x2, 0x91, 0x90, 
       0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 
       0x2, 0x2, 0x2, 0x93, 0x95, 0x7, 0x12, 0x2, 0x2, 0x94, 0x96, 0x5, 
       0x18, 0xd, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 0x24, 
       0x13, 0x2, 0x98, 0x21, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x4b, 
       0x2, 0x2, 0x9a, 0xa0, 0x5, 0x18, 0xd, 0x2, 0x9b, 0x9c, 0x7, 0x19, 
       0x2, 0x2, 0x9c, 0x9d, 0x7, 0x4b, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x18, 
       0xd, 0x2, 0x9e, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 0x2, 
       0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 
       0xa1, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 
       0xa4, 0x5, 0x26, 0x14, 0x2, 0xa4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa5, 
       0xa7, 0x7, 0x15, 0x2, 0x2, 0xa6, 0xa8, 0x5, 0x4, 0x3, 0x2, 0xa7, 
       0xa6, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x16, 0x2, 0x2, 0xaa, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 0x2a, 0x16, 0x2, 0xac, 0xad, 
       0x7, 0x18, 0x2, 0x2, 0xad, 0x29, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 
       0x8, 0x16, 0x1, 0x2, 0xaf, 0xb9, 0x5, 0x2c, 0x17, 0x2, 0xb0, 0xb1, 
       0x9, 0x4, 0x2, 0x2, 0xb1, 0xb9, 0x5, 0x2a, 0x16, 0x14, 0xb2, 0xb9, 
       0x7, 0x4b, 0x2, 0x2, 0xb3, 0xb9, 0x5, 0x30, 0x19, 0x2, 0xb4, 0xb5, 
       0x7, 0x11, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x2a, 0x16, 0x2, 0xb6, 0xb7, 
       0x7, 0x12, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xae, 
       0x3, 0x2, 0x2, 0x2, 0xb8, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb2, 0x3, 
       0x2, 0x2, 0x2, 0xb8, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb4, 0x3, 0x2, 
       0x2, 0x2, 0xb9, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0xc, 0x13, 
       0x2, 0x2, 0xbb, 0xbc, 0x9, 0x5, 0x2, 0x2, 0xbc, 0xf3, 0x5, 0x2a, 
       0x16, 0x14, 0xbd, 0xbe, 0xc, 0x12, 0x2, 0x2, 0xbe, 0xbf, 0x9, 0x6, 
       0x2, 0x2, 0xbf, 0xf3, 0x5, 0x2a, 0x16, 0x13, 0xc0, 0xc1, 0xc, 0x11, 
       0x2, 0x2, 0xc1, 0xc2, 0x9, 0x7, 0x2, 0x2, 0xc2, 0xf3, 0x5, 0x2a, 
       0x16, 0x12, 0xc3, 0xc4, 0xc, 0x10, 0x2, 0x2, 0xc4, 0xc5, 0x9, 0x8, 
       0x2, 0x2, 0xc5, 0xf3, 0x5, 0x2a, 0x16, 0x11, 0xc6, 0xc7, 0xc, 0xf, 
       0x2, 0x2, 0xc7, 0xc8, 0x9, 0x9, 0x2, 0x2, 0xc8, 0xf3, 0x5, 0x2a, 
       0x16, 0x10, 0xc9, 0xca, 0xc, 0xe, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x23, 
       0x2, 0x2, 0xcb, 0xf3, 0x5, 0x2a, 0x16, 0xf, 0xcc, 0xcd, 0xc, 0xd, 
       0x2, 0x2, 0xcd, 0xce, 0x7, 0x24, 0x2, 0x2, 0xce, 0xf3, 0x5, 0x2a, 
       0x16, 0xe, 0xcf, 0xd0, 0xc, 0xc, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x25, 
       0x2, 0x2, 0xd1, 0xf3, 0x5, 0x2a, 0x16, 0xd, 0xd2, 0xd3, 0xc, 0xb, 
       0x2, 0x2, 0xd3, 0xd4, 0x7, 0x2f, 0x2, 0x2, 0xd4, 0xf3, 0x5, 0x2a, 
       0x16, 0xc, 0xd5, 0xd6, 0xc, 0xa, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x30, 
       0x2, 0x2, 0xd7, 0xf3, 0x5, 0x2a, 0x16, 0xb, 0xd8, 0xd9, 0xc, 0x9, 
       0x2, 0x2, 0xd9, 0xda, 0x7, 0x31, 0x2, 0x2, 0xda, 0xf3, 0x5, 0x2a, 
       0x16, 0xa, 0xdb, 0xdc, 0xc, 0x8, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x32, 
       0x2, 0x2, 0xdd, 0xde, 0x5, 0x2a, 0x16, 0x2, 0xde, 0xdf, 0x7, 0x17, 
       0x2, 0x2, 0xdf, 0xe0, 0x5, 0x2a, 0x16, 0x9, 0xe0, 0xf3, 0x3, 0x2, 
       0x2, 0x2, 0xe1, 0xe2, 0xc, 0x7, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x32, 
       0x2, 0x2, 0xe3, 0xf3, 0x5, 0x2a, 0x16, 0x8, 0xe4, 0xe5, 0xc, 0x6, 
       0x2, 0x2, 0xe5, 0xe6, 0x9, 0xa, 0x2, 0x2, 0xe6, 0xf3, 0x5, 0x2a, 
       0x16, 0x6, 0xe7, 0xec, 0xc, 0x17, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x13, 
       0x2, 0x2, 0xe9, 0xea, 0x5, 0x2a, 0x16, 0x2, 0xea, 0xeb, 0x7, 0x14, 
       0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe8, 0x3, 0x2, 0x2, 
       0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 
       0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf0, 
       0xf1, 0xc, 0x15, 0x2, 0x2, 0xf1, 0xf3, 0x9, 0xb, 0x2, 0x2, 0xf2, 
       0xba, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xc0, 
       0x3, 0x2, 0x2, 0x2, 0xf2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xc6, 0x3, 
       0x2, 0x2, 0x2, 0xf2, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xcc, 0x3, 0x2, 
       0x2, 0x2, 0xf2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xd2, 0x3, 0x2, 0x2, 
       0x2, 0xf2, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xd8, 0x3, 0x2, 0x2, 0x2, 
       0xf2, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xf2, 
       0xe4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 
       0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 
       0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x4b, 
       0x2, 0x2, 0xf8, 0xfa, 0x7, 0x11, 0x2, 0x2, 0xf9, 0xfb, 0x5, 0x2e, 
       0x18, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 
       0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x12, 
       0x2, 0x2, 0xfd, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0x34, 
       0x1b, 0x2, 0xff, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x100, 0x109, 0x7, 0x42, 
       0x2, 0x2, 0x101, 0x109, 0x7, 0x43, 0x2, 0x2, 0x102, 0x109, 0x7, 0x44, 
       0x2, 0x2, 0x103, 0x109, 0x7, 0x45, 0x2, 0x2, 0x104, 0x109, 0x7, 0x46, 
       0x2, 0x2, 0x105, 0x109, 0x7, 0x47, 0x2, 0x2, 0x106, 0x109, 0x7, 0x48, 
       0x2, 0x2, 0x107, 0x109, 0x5, 0x32, 0x1a, 0x2, 0x108, 0x100, 0x3, 
       0x2, 0x2, 0x2, 0x108, 0x101, 0x3, 0x2, 0x2, 0x2, 0x108, 0x102, 0x3, 
       0x2, 0x2, 0x2, 0x108, 0x103, 0x3, 0x2, 0x2, 0x2, 0x108, 0x104, 0x3, 
       0x2, 0x2, 0x2, 0x108, 0x105, 0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 
       0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x31, 0x3, 
       0x2, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x13, 0x2, 0x2, 0x10b, 0x10d, 0x5, 
       0x34, 0x1b, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 
       0x7, 0x14, 0x2, 0x2, 0x10f, 0x33, 0x3, 0x2, 0x2, 0x2, 0x110, 0x115, 
       0x5, 0x2a, 0x16, 0x2, 0x111, 0x112, 0x7, 0x19, 0x2, 0x2, 0x112, 0x114, 
       0x5, 0x2a, 0x16, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x35, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x5, 0x38, 0x1d, 0x2, 0x119, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x9, 0x2, 0x2, 0x11b, 0x11c, 
       0x7, 0x11, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x2a, 0x16, 0x2, 0x11d, 0x11e, 
       0x7, 0x12, 0x2, 0x2, 0x11e, 0x121, 0x5, 0x6, 0x4, 0x2, 0x11f, 0x120, 
       0x7, 0xa, 0x2, 0x2, 0x120, 0x122, 0x5, 0x6, 0x4, 0x2, 0x121, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 0x5, 0x3c, 0x1f, 0x2, 0x124, 0x126, 
       0x5, 0x3e, 0x20, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x124, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 
       0x7, 0xc, 0x2, 0x2, 0x128, 0x129, 0x7, 0x11, 0x2, 0x2, 0x129, 0x12a, 
       0x5, 0x2a, 0x16, 0x2, 0x12a, 0x12b, 0x7, 0x12, 0x2, 0x2, 0x12b, 0x12c, 
       0x5, 0x6, 0x4, 0x2, 0x12c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
       0x7, 0xb, 0x2, 0x2, 0x12e, 0x130, 0x7, 0x11, 0x2, 0x2, 0x12f, 0x131, 
       0x5, 0x40, 0x21, 0x2, 0x130, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 
       0x7, 0x18, 0x2, 0x2, 0x133, 0x135, 0x5, 0x2a, 0x16, 0x2, 0x134, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x7, 0x18, 0x2, 0x2, 0x137, 0x139, 
       0x5, 0x34, 0x1b, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
       0x7, 0x12, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x6, 0x4, 0x2, 0x13c, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x140, 0x5, 0x10, 0x9, 0x2, 0x13e, 0x140, 
       0x5, 0x34, 0x1b, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13e, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x41, 0x3, 0x2, 0x2, 0x2, 0x141, 0x145, 
       0x5, 0x44, 0x23, 0x2, 0x142, 0x145, 0x5, 0x46, 0x24, 0x2, 0x143, 
       0x145, 0x5, 0x48, 0x25, 0x2, 0x144, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0xe, 0x2, 0x2, 0x147, 
       0x148, 0x7, 0x18, 0x2, 0x2, 0x148, 0x45, 0x3, 0x2, 0x2, 0x2, 0x149, 
       0x14a, 0x7, 0xd, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x18, 0x2, 0x2, 0x14b, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x7, 0x10, 0x2, 0x2, 0x14d, 
       0x14f, 0x5, 0x2a, 0x16, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14e, 
       0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
       0x151, 0x7, 0x18, 0x2, 0x2, 0x151, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1f, 
       0x4b, 0x52, 0x5b, 0x63, 0x6e, 0x75, 0x78, 0x82, 0x89, 0x91, 0x95, 
       0xa0, 0xa7, 0xb8, 0xee, 0xf2, 0xf4, 0xfa, 0x108, 0x10c, 0x115, 0x121, 
       0x125, 0x130, 0x134, 0x138, 0x13f, 0x144, 0x14e, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

StaticScriptParser::Initializer StaticScriptParser::_init;
