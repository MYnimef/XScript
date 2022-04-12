//
// Created by Ivan Markov on 09.04.2022.
//

#include "ExpLogicalGreater.h"

ExpLogicalGreater::ExpLogicalGreater() {
    type = EXP_OP_GREATER;
}

void ExpLogicalGreater::action(const CompilerArgs& args) const {

    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 > *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpLogicalGreater::toString() const {
    return ">";
}
