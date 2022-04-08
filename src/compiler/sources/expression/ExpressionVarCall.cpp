//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionVarCall.h"
#include "VariableInteger.h"
#include "VariableDouble.h"
#include "VariableString.h"
#include "VariableBool.h"

ExpressionVarCall::ExpressionVarCall(const std::string &value):
id(value) {
    type = EXP_ID;
}

void ExpressionVarCall::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {

    for (auto scope: variablesGlobal) {
        if (callVariableFrom(scope, stack)) {
            return;
        }
    }

    if (!callVariableFrom(variables, stack)) {
        throw std::overflow_error("usage of undeclared var");
    }
}

std::string ExpressionVarCall::toString() const {
    return id;
}

bool ExpressionVarCall::callVariableFrom(std::map<std::string, Variable*>* container,std::stack<Variable*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        auto var = it->second;
        switch (var->getType()) {
            case Variable::BOOL_VAR:
                stack.push(new VariableBool(var->getBool()));
                return true;
            case Variable::INTEGER_VAR:
                stack.push(new VariableInteger(var->getInteger()));
                return true;
            case Variable::DOUBLE_VAR:
                stack.push(new VariableDouble(var->getDouble()));
                return true;
            case Variable::STRING_VAR:
                stack.push(new VariableString(var->getString()));
                return true;
        }
    }

    return false;
}
