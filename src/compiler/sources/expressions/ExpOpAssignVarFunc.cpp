//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExpOpAssignVarFunc.h"
#include "ExcExp.h"

ExpOpAssignVarFunc::ExpOpAssignVarFunc(const int& lineNum, const std::string &value):
Exp(EXP_OP_ASSIGN_VAR_FUNC, lineNum),
id(value) {
}

void ExpOpAssignVarFunc::action(const InterpreterArgs &args) const {
    if (!args.stack.empty()) {
        auto val = args.stack.top();
        args.stack.pop();

        args.variables->insert_or_assign(id, val);
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpOpAssignVarFunc::toString() const {
    return id;
}
