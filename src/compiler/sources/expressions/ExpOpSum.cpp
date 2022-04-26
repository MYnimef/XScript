//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpOpSum.h"
#include "ExcExp.h"

ExpOpSum::ExpOpSum(const int& lineNum):
Exp(EXP_OP_SUM, lineNum) {}

void ExpOpSum::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 + *arg2);

        delete arg1;
        delete arg2;
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpOpSum::toString() const {
    return "+";
}
