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
    const std::map<TokenType, std::regex> lexems;
    std::list<Token> tokens;

    void addToken(const std::string& input, const int& lineNum);
    bool checkToken(const std::string&);

    TokenType checkKeyWord(const std::string& input);
    TokenType checkOperator(const std::string& input);

public:
    Lexer();
    ~Lexer();
    void scanFile(const std::string&);
    std::list<Token> getTokens();
};
