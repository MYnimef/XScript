//
// Created by Ivan Markov on 09.04.2022.
//

#include "ExpLogicalGreaterOrEqual.h"
#include "ExcExp.h"

ExpLogicalGreaterOrEqual::ExpLogicalGreaterOrEqual(const int& lineNum):
Exp(EXP_OP_GREATER_OR_EQUAL, lineNum) {
}

void ExpLogicalGreaterOrEqual::action(const CompilerArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 >= *arg2);

        delete arg1;
        delete arg2;
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpLogicalGreaterOrEqual::toString() const {
    return ">";
}
