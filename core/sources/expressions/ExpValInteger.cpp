//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValInteger.h"
#include "VarInteger.h"

ExpValInteger::ExpValInteger(const int& lineNum, const long long value):
Exp(EXP_INTEGER, lineNum),
value(value) {}

ExpValInteger::ExpValInteger(const int& lineNum, const std::string& value):
Exp(EXP_INTEGER, lineNum),
value(std::stoll(value)) {}

void ExpValInteger::action(const InterpreterArgs& args) const {
    args.stack.push(new VarInteger(lineNum, value));
}

std::string ExpValInteger::toString() const {
    return std::to_string(value);
}
