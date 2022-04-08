//
// Created by Ivan Markov on 05.04.2022.
//

#include "Expression.h"

Expression::Expression() {

}

Expression::~Expression() {

}

ExpressionType Expression::getType() const {
    return type;
}

bool Expression::isOperator() const {
    return (
            type == EXP_OP_ASSIGNMENT ||
            type == EXP_OP_SUM ||
            type == EXP_OP_SUBTRACTION ||
            type == EXP_OP_MULTIPLICATION ||
            type == EXP_OP_DIVISION
    );
}
