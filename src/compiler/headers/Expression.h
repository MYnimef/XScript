//
// Created by Ivan Markov on 05.04.2022.
//

#pragma once

#include <string>
#include <map>
#include <stack>
#include "Variable.h"

enum ExpressionType {
    EXP_VAR_INITIALIZATION,

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

    EXP_CODE_BLOCK,
    EXP_ADD_TO_LOCAL,
    EXP_GET_FROM_LOCAL,
};

class Expression final {
private:
    ExpressionType type;
    std::string value;

public:
    Expression(ExpressionType type, const std::string& value);

    [[nodiscard]] ExpressionType getType() const;
    [[nodiscard]] std::string getValue() const;

    void action(
            std::map<std::string, Variable>& constants,
            std::map<std::string, Variable>& variables,
            std::stack<std::string>& stackConstantsId,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable>& stack
            );

    [[nodiscard]] bool isOperator() const;
};
