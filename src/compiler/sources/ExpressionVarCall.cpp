//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionVarCall.h"

ExpressionVarCall::ExpressionVarCall(const std::string &value):
id(value) {
    type = EXP_ID;
}

void ExpressionVarCall::action(
        std::map<std::string, Variable> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable> &stack
        ) const {
    auto it = variables.find(id);
    if (it != variables.end()) {
        stack.push(it->second);
    } else {
        throw std::overflow_error("usage of undeclared var");
    }
}
