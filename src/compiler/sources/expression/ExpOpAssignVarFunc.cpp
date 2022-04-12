//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExpOpAssignVarFunc.h"

ExpOpAssignVarFunc::ExpOpAssignVarFunc(const std::string &value):
id(value) {
    type = EXP_OP_ASSIGN_VAR_FUNC;
}

void ExpOpAssignVarFunc::action(const CompilerArgs &args) const {
    auto val = args.stack.top();
    args.stack.pop();

    args.variables->insert_or_assign(id, val);
}

std::string ExpOpAssignVarFunc::toString() const {
    return id;
}