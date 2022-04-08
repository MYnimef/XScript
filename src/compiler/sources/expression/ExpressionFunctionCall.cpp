//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionFunctionCall.h"

ExpressionFunctionCall::ExpressionFunctionCall(const std::string &value):
name(value) {
    type = EXP_FUNC;
}

void
ExpressionFunctionCall::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {

}

std::string ExpressionFunctionCall::toString() const {
    return "function " + name;
}
