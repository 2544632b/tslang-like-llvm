
// Generated from /Users/chan/Desktop/StaticScript-master-2/grammar/StaticScriptLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  StaticScriptLexer : public antlr4::Lexer {
public:
  enum {
    Boolean = 1, Integer = 2, Number = 3, String = 4, Let = 5, Const = 6, 
    If = 7, Else = 8, For = 9, While = 10, Break = 11, Continue = 12, Function = 13, 
    Return = 14, OpenParen = 15, CloseParen = 16, OpenBracket = 17, CloseBracket = 18, 
    OpenBrace = 19, CloseBrace = 20, Colon = 21, SemiColon = 22, Comma = 23, 
    PlusPlus = 24, MinusMinus = 25, Not = 26, BitNot = 27, Plus = 28, Minus = 29, 
    Multiply = 30, Divide = 31, Modulus = 32, BitAnd = 33, BitXOr = 34, 
    BitOr = 35, ShiftLeft = 36, ArithmeticShiftRight = 37, LogicalShiftRight = 38, 
    LessThan = 39, GreaterThan = 40, LessThanEquals = 41, GreaterThanEquals = 42, 
    Equals = 43, NotEquals = 44, And = 45, Or = 46, Nullish = 47, ConditionalQuestion = 48, 
    Assign = 49, PlusAssign = 50, MinusAssign = 51, MultiplyAssign = 52, 
    DivideAssign = 53, ModulusAssign = 54, BitAndAssign = 55, BitXorAssign = 56, 
    BitOrAssign = 57, ShiftLeftAssign = 58, ArithmeticShiftRightAssign = 59, 
    LogicalShiftRightAssign = 60, AndAssign = 61, OrAssign = 62, NullLiteral = 63, 
    BooleanLiteral = 64, DecimalIntegerLiteral = 65, HexIntegerLiteral = 66, 
    OctalIntegerLiteral = 67, BinaryIntegerLiteral = 68, FloatLiteral = 69, 
    StringLiteral = 70, WhiteSpaces = 71, LineTerminator = 72, Identifier = 73, 
    MultiLineComment = 74, SingleLineComment = 75, UnexpectedCharacter = 76
  };

  enum {
    ERROR = 2
  };

  explicit StaticScriptLexer(antlr4::CharStream *input);
  ~StaticScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

