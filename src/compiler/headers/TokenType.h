//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>

enum EType {
    ID,
    DOUBLE_DIGIT,
    INT_DIGIT,
    STRING,
    KEY_WORD,
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    OPERATOR,
    SEMICOLON,
};

class TokenType final {
private:
    EType type;

public:
    TokenType(EType);
    ~TokenType();

    EType getType() const;

    std::string toString();

    bool operator <(const TokenType&) const;
};
