//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionValDouble.h"
#include "VariableDouble.h"

ExpressionValDouble::ExpressionValDouble(const std::string& value):
value(std::stold(value)) {
    type = EXP_DOUBLE;
}

void ExpressionValDouble::action(const CompilerArgs& args) const {

    args.stack.push(new VariableDouble(value));
}

std::string ExpressionValDouble::toString() const {
    return std::to_string(value);
}
