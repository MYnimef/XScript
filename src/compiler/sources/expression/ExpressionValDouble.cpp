//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionValDouble.h"
#include "VariableDouble.h"

ExpressionValDouble::ExpressionValDouble(const std::string& value):
value(std::stod(value)) {
    type = EXP_DOUBLE;
}

void ExpressionValDouble::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack) const {
    stack.push(new VariableDouble(value));
}
