//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpDiv.h"

ExpressionOpDiv::ExpressionOpDiv() {
    type = EXP_OP_DIVISION;
}

void ExpressionOpDiv::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {
    auto arg2 = stack.top();
    stack.pop();
    auto arg1 = stack.top();
    stack.pop();
    stack.push(*arg1 / *arg2);

    delete arg1;
    delete arg2;
}
