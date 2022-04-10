//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExpressionOpNot.h"

ExpressionOpNot::ExpressionOpNot() {
    type = EXP_OP_NOT;
}

void ExpressionOpNot::action(const CompilerArgs &args) const {
    auto arg = args.stack.top();
    args.stack.pop();
    args.stack.push(!*arg);
    delete arg;
}

std::string ExpressionOpNot::toString() const {
    return "!";
}
