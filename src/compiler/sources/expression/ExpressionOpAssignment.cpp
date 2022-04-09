//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpAssignment.h"

ExpressionOpAssignment::ExpressionOpAssignment() {
    type = EXP_OP_ASSIGNMENT;
}

void ExpressionOpAssignment::action(const CompilerArgs& args) const {

    auto var = args.stack.top();
    args.stack.pop();
    auto id = args.stackVariablesId.top();
    args.stackVariablesId.pop();

    for (auto scope: args.variablesGlobal) {
        auto it = scope->find(id);
        if (it != scope->end()) {
            scope->insert_or_assign(id, var);
            return;
        }
    }

    args.variables->insert_or_assign(id, var);
}

std::string ExpressionOpAssignment::toString() const {
    return "=";
}
