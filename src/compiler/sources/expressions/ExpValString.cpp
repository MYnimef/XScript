//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValString.h"
#include "VarString.h"

ExpValString::ExpValString(const int& lineNum, const std::string& value):
Exp(EXP_STRING, lineNum),
value(value.substr(1, value.size() - 2)) {}

void ExpValString::action(const InterpreterArgs& args) const {
    args.stack.push(new VarString(lineNum, value));
}

std::string ExpValString::toString() const {
    return value;
}
