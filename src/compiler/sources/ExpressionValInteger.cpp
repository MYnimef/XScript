//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionValInteger.h"

ExpressionValInteger::ExpressionValInteger(const std::string& value):
value(std::stoi(value)) {
    type = EXP_INTEGER;
}

void ExpressionValInteger::action(
        std::map<std::string, Variable> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable> &stack
        ) const {
    stack.push(Variable(value));
}
