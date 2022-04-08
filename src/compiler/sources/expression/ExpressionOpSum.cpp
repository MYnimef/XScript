//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpSum.h"

ExpressionOpSum::ExpressionOpSum() {
    type = EXP_OP_SUM;
}

void ExpressionOpSum::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {

    auto arg2 = stack.top();
    stack.pop();
    auto arg1 = stack.top();
    stack.pop();
    stack.push(*arg1 + *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpressionOpSum::toString() const {
    return "+";
}
