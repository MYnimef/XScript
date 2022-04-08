//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionVarInit.h"

ExpressionVarInit::ExpressionVarInit(const std::string &value):
id(value) {
    type = EXP_VAR_INITIALIZATION;
}

void ExpressionVarInit::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {

    stackVariablesId.push(id);
}

std::string ExpressionVarInit::toString() const {
    return id;
}
