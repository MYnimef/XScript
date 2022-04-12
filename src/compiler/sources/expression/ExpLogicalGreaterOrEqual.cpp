//
// Created by Ivan Markov on 09.04.2022.
//

#include "ExpLogicalGreaterOrEqual.h"

ExpLogicalGreaterOrEqual::ExpLogicalGreaterOrEqual() {
    type = EXP_OP_GREATER_OR_EQUAL;
}

void ExpLogicalGreaterOrEqual::action(const CompilerArgs& args) const {

    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 >= *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpLogicalGreaterOrEqual::toString() const {
    return ">";
}
