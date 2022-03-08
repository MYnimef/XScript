//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>
#include "TokenType.h"

class Token final {
private:
    TokenType type;
    std::string value;

public:
    Token(const TokenType&, const std::string&);
    ~Token();
    Token(const Token&);

    EType getType();
    std::string getValue();

    std::string toString();
};
