//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpDiv.h"

ExpOpDiv::ExpOpDiv() {
    type = EXP_OP_DIVISION;
}

void ExpOpDiv::action(const CompilerArgs& args) const {

    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 / *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpOpDiv::toString() const {
    return "/";
}
