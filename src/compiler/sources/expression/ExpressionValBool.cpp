//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionValBool.h"
#include "VariableBool.h"

ExpressionValBool::ExpressionValBool(const std::string &value):
value(value == "true") {
    type = EXP_BOOL;
}

void ExpressionValBool::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {

    stack.push(new VariableBool(value));
}

std::string ExpressionValBool::toString() const {
    return (value ? "true" : "false");
}
