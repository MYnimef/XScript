//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpVarCall.h"
#include "ExcExp.h"

ExpVarCall::ExpVarCall(const int& lineNum, const std::string& value):
Exp(EXP_ID, lineNum),
id(value) {}

void ExpVarCall::action(const InterpreterArgs& args) const {
    for (auto scope: args.variablesGlobal) {
        if (callVariableFrom(scope, args.stack)) {
            return;
        }
    }

    if (!callVariableFrom(args.variables, args.stack)) {
        throw ExcExp("usage of undeclared var '" + id +  "'", lineNum);
    }
}

std::string ExpVarCall::toString() const {
    return id;
}

bool ExpVarCall::callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        stack.push(it->second->copy(lineNum));
        return true;
    }
    return false;
}
