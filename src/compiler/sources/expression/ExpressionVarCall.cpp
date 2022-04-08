//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionVarCall.h"
#include "VariableInteger.h"
#include "VariableDouble.h"
#include "VariableString.h"

ExpressionVarCall::ExpressionVarCall(const std::string &value):
id(value) {
    type = EXP_ID;
}

void ExpressionVarCall::action(
        std::map<std::string, Variable *> &variables,
        std::stack<std::string> &stackVariablesId,
        std::stack<Variable *> &stack
        ) const {
    auto it = variables.find(id);
    if (it != variables.end()) {
        auto var = it->second;
        switch (var->getType()) {
            case Variable::INTEGER_VAR:
                stack.push(new VariableInteger(var->getInteger()));
                break;
            case Variable::DOUBLE_VAR:
                stack.push(new VariableDouble(var->getDouble()));
                break;
            case Variable::STRING_VAR:
                stack.push(new VariableString(var->getString()));
                break;
        }
    } else {
        throw std::overflow_error("usage of undeclared var");
    }
}
