//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>
#include <list>

enum TokenType {
    ID,

    DOUBLE_DIGIT,
    INT_DIGIT,
    STRING,

    FUNC_KW,
    IF_KW,
    ELSE_KW,
    WHILE_KW,
    FOR_KW,

    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,

    ASSIGN_OP,
    INCREMENT_OP,
    DECREMENT_OP,
    SUM_OP,
    SUB_OP,
    MULT_OP,
    DIV_OP,

    COMMA,
    SEMICOLON,
};

class Token final {
private:
    TokenType type;
    std::string value;

public:
    Token(const TokenType&, const std::string&);
    ~Token();
    Token(const Token&);

    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getValue() const;

    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string typeToString() const;

    [[nodiscard]] bool isOperator() const;
    [[nodiscard]] bool isKeyWord() const;
};
