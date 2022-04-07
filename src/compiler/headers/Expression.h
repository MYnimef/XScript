//
// Created by Ivan Markov on 05.04.2022.
//

#pragma once

#include <string>

enum ExpressionType {
    EXP_VAR_INITIALIZATION,
    EXP_LET_INITIALIZATION,

    EXP_ID,
    EXP_INTEGER,
    EXP_DOUBLE,
    EXP_STRING,

    EXP_OP_ASSIGNMENT,
    EXP_OP_SUM,
    EXP_OP_SUBTRACTION,
    EXP_OP_MULTIPLICATION,
    EXP_OP_DIVISION,

    EXP_LOOP_WHILE,
    EXP_LOOP_FOR,

    EXP_FUNC,
    EXP_FUNC_DEFINITION,
};

class Expression final {
private:
    ExpressionType type;
    std::string value;

public:
    Expression(ExpressionType type, const std::string& value);

    [[nodiscard]] ExpressionType getType() const;
    [[nodiscard]] std::string getValue() const;

    bool isOperator();
};