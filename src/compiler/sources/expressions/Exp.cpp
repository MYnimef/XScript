//
// Created by Ivan Markov on 05.04.2022.
//

#include "Exp.h"

Exp::Exp(const ExpressionType& type, const int& lineNum):
type(type),
lineNum(lineNum) {

}

Exp::~Exp() {

}

ExpressionType Exp::getType() const {
    return type;
}

bool Exp::isOperation() const {
    return (isUnaryOperation() || isBinaryOperation());
}

bool Exp::isUnaryOperation() const {
    return (
            type == EXP_OP_NOT ||
            type == EXP_OP_ASSIGN_VAR ||
            type == EXP_OP_ASSIGN_VAR_FUNC
            );
}

bool Exp::isBinaryOperation() const {
    return (
            type == EXP_OP_SUM ||
            type == EXP_OP_SUBTRACTION ||
            type == EXP_OP_MULTIPLICATION ||
            type == EXP_OP_DIVISION ||
            type == EXP_OP_EQUAL ||
            type == EXP_OP_NOT_EQUAL ||
            type == EXP_OP_GREATER_OR_EQUAL ||
            type == EXP_OP_SMALLER_OR_EQUAL ||
            type == EXP_OP_SMALLER ||
            type == EXP_OP_GREATER ||
            type == EXP_LOGICAL_AND ||
            type == EXP_LOGICAL_OR
    );
}
