//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpAssignment.h"

ExpressionOpAssignment::ExpressionOpAssignment() {
    type = EXP_OP_ASSIGNMENT;
}

void ExpressionOpAssignment::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {

    auto var = stack.top();
    stack.pop();
    auto id = stackVariablesId.top();
    stackVariablesId.pop();

    for (auto scope: variablesGlobal) {
        auto it = scope->find(id);
        if (it != scope->end()) {
            scope->insert_or_assign(id, var);
            return;
        }
    }

    variables->insert_or_assign(id, var);
}

std::string ExpressionOpAssignment::toString() const {
    return "=";
}
