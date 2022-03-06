//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <map>
#include <list>
#include <regex>
#include "Type.h"
#include "Token.h"

class Lexer final {
private:
    const std::map<Type, std::regex> lexems;
    std::list<Token*> tokens;

    void addToken(const std::string&);

public:
    Lexer();
    ~Lexer();
    void scanFile(const std::string&);
    std::list<Token*> getTokens();
};
