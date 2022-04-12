//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpVarCall.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarBool.h"

ExpVarCall::ExpVarCall(const std::string &value):
id(value) {
    type = EXP_ID;
}

void ExpVarCall::action(const CompilerArgs& args) const {

    for (auto scope: args.variablesGlobal) {
        if (callVariableFrom(scope, args.stack)) {
            return;
        }
    }

    if (!callVariableFrom(args.variables, args.stack)) {
        throw std::overflow_error("usage of undeclared var");
    }
}

std::string ExpVarCall::toString() const {
    return id;
}

bool ExpVarCall::callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        auto var = it->second;
        switch (var->getType()) {
            case Var::BOOL_VAR:
                stack.push(new VarBool(var->getBool()));
                return true;
            case Var::INTEGER_VAR:
                stack.push(new VarInteger(var->getInteger()));
                return true;
            case Var::DOUBLE_VAR:
                stack.push(new VarDouble(var->getDouble()));
                return true;
            case Var::STRING_VAR:
                stack.push(new VarString(var->getString()));
                return true;
        }
    }

    return false;
}
