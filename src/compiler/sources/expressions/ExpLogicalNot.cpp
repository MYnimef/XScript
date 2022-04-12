//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExpLogicalNot.h"

ExpLogicalNot::ExpLogicalNot() {
    type = EXP_OP_NOT;
}

void ExpLogicalNot::action(const CompilerArgs &args) const {
    auto arg = args.stack.top();
    args.stack.pop();
    args.stack.push(!*arg);
    delete arg;
}

std::string ExpLogicalNot::toString() const {
    return "!";
}
