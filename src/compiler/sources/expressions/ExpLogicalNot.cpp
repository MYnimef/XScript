//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExpLogicalNot.h"
#include "ExcExp.h"

ExpLogicalNot::ExpLogicalNot(const int& lineNum):
Exp(EXP_OP_NOT, lineNum) {}

void ExpLogicalNot::action(const InterpreterArgs &args) const {
    if (!args.stack.empty()) {
        auto arg = args.stack.top();
        args.stack.pop();
        args.stack.push(!*arg);
        delete arg;
    } else {
        throw ExcExp("function doesn't return any value", lineNum);
    }
}

std::string ExpLogicalNot::toString() const {
    return "!";
}
