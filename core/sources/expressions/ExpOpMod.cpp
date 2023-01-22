//
// Created by Ivan Markov on 22.01.2023.
//

#include "ExpOpMod.h"
#include "ExcExp.h"

ExpOpMod::ExpOpMod(const int& lineNum):
        Exp(EXP_OP_MOD, lineNum) {}

void ExpOpMod::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 % *arg2);

        delete arg1;
        delete arg2;
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpOpMod::toString() const {
    return "%";
}