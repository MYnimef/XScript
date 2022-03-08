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

class Type final {
private:
    EType type;

public:
    Type(EType);
    ~Type();

    EType getType();

    std::string toString();

    bool operator <(const Type&) const;
};
