//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <map>
#include <list>
#include <regex>
#include "Type.h"
#include "Token.h"

class Lexer {
private:
    static const std::map<Type, std::regex> lexems;
    std::list<Token*> tokens;

public:
    Lexer();
    ~Lexer();
    void addToken(const std::string& input);
    std::list<Token*> getTokens();
};
