//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpSub.h"
#include "ExcExp.h"

ExpOpSub::ExpOpSub(const int& lineNum):
Exp(EXP_OP_SUBTRACTION, lineNum) {
}

void ExpOpSub::action(const CompilerArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 - *arg2);

        delete arg1;
        delete arg2;
    } else {
        throw ExcExp("function doesn't return any value at line " + std::to_string(lineNum));
    }
}

std::string ExpOpSub::toString() const {
    return "-";
}
