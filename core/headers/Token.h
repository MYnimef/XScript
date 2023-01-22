//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>

enum TokenType {
    DECREMENT_OP,
    INCREMENT_OP,
    STRING,
    INT_DIGIT,
    DOUBLE_DIGIT,
    ID,
    BOOL,
    FUNC_KW,
    IF_KW,
    ELSE_KW,
    WHILE_KW,
    BREAK_KW,
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    ASSIGN_OP,
    SUM_OP,
    SUB_OP,
    MULT_OP,
    DIV_OP,
    MOD_OP,
    OR_OP,
    AND_OP,
    GREATER_OP,
    SMALLER_OP,
    GREATER_OR_EQUAL_OP,
    SMALLER_OR_EQUAL_OP,
    NOT_OP,
    EQUAL_OP,
    NOT_EQUAL_OP,
    COMMA,
    SEMICOLON,
};

class Token final {
private:
    const TokenType type;
    const std::string value;
    const int lineNum;

public:
    Token(const TokenType&, const std::string&, const int& lineNum);
    Token(const Token&);
    ~Token();

    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getValue() const;
    [[nodiscard]] int getLineNum() const;

    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string typeToString() const;

    [[nodiscard]] bool isOperator() const;
    [[nodiscard]] bool isKeyWord() const;
};
