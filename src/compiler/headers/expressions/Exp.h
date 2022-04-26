//
// Created by Ivan Markov on 05.04.2022.
//

#pragma once

#include "InterpreterArgs.h"
#include "Var.h"

enum ExpressionType {
    EXP_ID,
    EXP_BOOL,
    EXP_INTEGER,
    EXP_DOUBLE,
    EXP_STRING,

    EXP_OP_MULTIPLICATION,
    EXP_OP_DIVISION,
    EXP_OP_SUM,
    EXP_OP_SUBTRACTION,
    EXP_OP_SMALLER,
    EXP_OP_SMALLER_OR_EQUAL,
    EXP_OP_GREATER,
    EXP_OP_GREATER_OR_EQUAL,
    EXP_OP_EQUAL,
    EXP_OP_NOT_EQUAL,
    EXP_LOGICAL_AND,
    EXP_LOGICAL_OR,
    EXP_OP_NOT,
    EXP_OP_ASSIGN_VAR,
    EXP_OP_ASSIGN_VAR_FUNC,

    EXP_IF,

    EXP_LOOP_WHILE,
    EXP_LOOP_FOR,

    EXP_FUNC_CALL,
    EXP_FUNC_DEFINITION,

    EXP_CODE_BLOCK,

    EXP_BRACKET_L,
    EXP_BRACKET_R,
};

class Exp {
protected:
    ExpressionType type;
    int lineNum;

public:
    Exp(const ExpressionType& type, const int& lineNum);
    virtual ~Exp();

    [[nodiscard]] ExpressionType getType() const;

    virtual void action(const InterpreterArgs& args) const = 0;

    [[nodiscard]] bool isOperation() const;
    [[nodiscard]] bool isUnaryOperation() const;
    [[nodiscard]] bool isBinaryOperation() const;

    [[nodiscard]] virtual std::string toString() const = 0;
};

class ExpressionBracketL final: public Exp {
public:
    ExpressionBracketL(): Exp(EXP_BRACKET_L, 0) { }
    void action(const InterpreterArgs& args) const override { }
    [[nodiscard]] std::string toString() const override { return "("; }
};

class ExpressionBracketR final: public Exp {
public:
    ExpressionBracketR(): Exp(EXP_BRACKET_R, 0) { }
    void action(const InterpreterArgs& args) const override { }
    [[nodiscard]] std::string toString() const override { return ")"; }
};
