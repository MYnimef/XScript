//
// Created by Ivan Markov on 09.04.2022.
//

#include "ExpressionOpSmaller.h"

ExpressionOpSmaller::ExpressionOpSmaller() {
    type = EXP_OP_SMALLER;
}

void ExpressionOpSmaller::action(
        std::list<std::map<std::string, Variable *> *> variablesGlobal,
        std::map<std::string, Variable *> *variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {

    auto arg2 = stack.top();
    stack.pop();
    auto arg1 = stack.top();
    stack.pop();
    stack.push(*arg1 < *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpressionOpSmaller::toString() const {
    return "<";
}
