//
// Created by Ivan Markov on 05.04.2022.
//

#pragma once

#include <list>
#include <string>
#include <map>
#include <stack>
#include "Variable.h"

enum ExpressionType {
    EXP_VAR_INITIALIZATION,

    EXP_ID,
    EXP_BOOL,
    EXP_INTEGER,
    EXP_DOUBLE,
    EXP_STRING,

    EXP_OP_ASSIGNMENT,
    EXP_OP_SUM,
    EXP_OP_SUBTRACTION,
    EXP_OP_MULTIPLICATION,
    EXP_OP_DIVISION,

    EXP_IF,

    EXP_LOOP_WHILE,
    EXP_LOOP_FOR,

    EXP_FUNC,
    EXP_FUNC_DEFINITION,

    EXP_CODE_BLOCK,
    EXP_ADD_TO_LOCAL,
    EXP_GET_FROM_LOCAL,

    EXP_BRACKET_L,
    EXP_BRACKET_R,
};

class Expression {
protected:
    ExpressionType type;

public:
    Expression();
    virtual ~Expression();

    [[nodiscard]] ExpressionType getType() const;

    virtual void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
            ) const = 0;

    [[nodiscard]] bool isOperator() const;

    [[nodiscard]] virtual std::string toString() const = 0;
};

class ExpressionBracketL: public Expression {
public:
    ExpressionBracketL() {
        type = EXP_BRACKET_L;
    }

    void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
            ) const override {

    }

    [[nodiscard]] std::string toString() const override {
        return "(";
    }
};

class ExpressionBracketR: public Expression {
public:
    ExpressionBracketR() {
        type = EXP_BRACKET_R;
    }

    void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
           ) const override {

    }

    [[nodiscard]] std::string toString() const override {
        return ")";
    }
};
