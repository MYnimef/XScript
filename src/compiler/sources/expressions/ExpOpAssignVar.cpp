//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpAssignVar.h"
#include "ExcExp.h"

ExpOpAssignVar::ExpOpAssignVar(const int& lineNum, const std::string &value):
Exp(EXP_OP_ASSIGN_VAR, lineNum),
id(value) {
}

void ExpOpAssignVar::action(const InterpreterArgs& args) const {
    if (!args.stack.empty()) {
        auto val = args.stack.top();
        args.stack.pop();

        for (auto scope: args.variablesGlobal) {
            auto it = scope->find(id);
            if (it != scope->end()) {
                auto var = it->second;
                scope->insert_or_assign(id, val);
                delete var;
                return;
            }
        }

        auto it = args.variables->find(id);
        if (it != args.variables->end()) {
            auto var = it->second;
            args.variables->insert_or_assign(id, val);
            delete var;
        } else {
            args.variables->insert_or_assign(id, val);
        }
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpOpAssignVar::toString() const {
    return id;
}
