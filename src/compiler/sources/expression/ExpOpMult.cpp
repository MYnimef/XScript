//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpMult.h"

ExpOpMult::ExpOpMult() {
    type = EXP_OP_MULTIPLICATION;
}

void ExpOpMult::action(const CompilerArgs& args) const {

    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 * *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpOpMult::toString() const {
    return "*";
}
