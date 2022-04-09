//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <map>
#include <list>
#include <regex>
#include "Token.h"

class Lexer final {
private:
    enum Lexem {
        LEX_ONE_CHAR,
        LEX_TWO_CHAR,
        LEX_KEY_WORD,
        LEX_STRING,
        LEX_INT_DIGIT,
        LEX_DOUBLE_DIGIT,
        LEX_ID,
    };

    const std::map<Lexem, std::regex> lexems;
    std::list<Token> tokens;

    void addToken(const std::string& input, const int& lineNum);
    bool checkToken(const std::string&);

    TokenType checkKeyWord(const std::string& input);
    TokenType checkOneChar(const std::string& input);
    TokenType checkTwoChar(const std::string& input);

public:
    Lexer();
    ~Lexer();
    void scanFile(const std::string&);
    std::list<Token> getTokens();
};
