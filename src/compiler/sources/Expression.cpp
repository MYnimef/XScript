//
// Created by Ivan Markov on 05.04.2022.
//

#include "Expression.h"

Expression::Expression(ExpressionType type, const std::string& value):
type(type),
value(value) {

}

ExpressionType Expression::getType() const {
    return type;
}

std::string Expression::getValue() const {
    return value;
}

bool Expression::isOperator() {
    return (
            type == EXP_OP_ASSIGNMENT ||
            type == EXP_OP_SUM ||
            type == EXP_OP_SUBTRACTION ||
            type == EXP_OP_MULTIPLICATION ||
            type == EXP_OP_DIVISION
    );
}
