//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionValString.h"
#include "VariableString.h"

ExpressionValString::ExpressionValString(const std::string& value) {
    this->value = value.substr(1, value.size() - 2);
    type = EXP_STRING;
}

void ExpressionValString::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {
    stack.push(new VariableString(value));
}

std::string ExpressionValString::toString() const {
    return value;
}
