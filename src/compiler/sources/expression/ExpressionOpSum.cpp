//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionOpSum.h"

ExpressionOpSum::ExpressionOpSum() {
    type = EXP_OP_SUM;
}

void ExpressionOpSum::action(const CompilerArgs& args) const {
    auto arg2 = args.stack.top();
    args.stack.pop();
    auto arg1 = args.stack.top();
    args.stack.pop();
    args.stack.push(*arg1 + *arg2);

    delete arg1;
    delete arg2;
}

std::string ExpressionOpSum::toString() const {
    return "+";
}
