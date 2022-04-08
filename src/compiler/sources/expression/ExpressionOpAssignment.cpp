//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpAssignment.h"

ExpressionOpAssignment::ExpressionOpAssignment() {
    type = EXP_OP_ASSIGNMENT;
}

void ExpressionOpAssignment::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {
    auto var = stack.top();

    variables.insert_or_assign(stackVariablesId.top(), var);
    stackVariablesId.pop();

    stack.pop();
}
