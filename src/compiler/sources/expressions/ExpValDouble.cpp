//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValDouble.h"
#include "VarDouble.h"

ExpValDouble::ExpValDouble(const int& lineNum, const std::string& value):
Exp(EXP_DOUBLE, lineNum),
value(std::stold(value)) {}

void ExpValDouble::action(const InterpreterArgs& args) const {
    args.stack.push(new VarDouble(lineNum, value));
}

std::string ExpValDouble::toString() const {
    return std::to_string(value);
}
