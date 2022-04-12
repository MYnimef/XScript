//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpSum.h"

ExpOpSum::ExpOpSum() {
    type = EXP_OP_SUM;
}

void ExpOpSum::action(const CompilerArgs& args) const {
    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 + *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpOpSum::toString() const {
    return "+";
}
