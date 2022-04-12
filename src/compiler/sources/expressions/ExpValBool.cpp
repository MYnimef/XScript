//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpValBool.h"
#include "VarBool.h"

ExpValBool::ExpValBool(const int& lineNum, const std::string &value):
Exp(EXP_BOOL, lineNum),
value(value == "true") {
}

void ExpValBool::action(const CompilerArgs& args) const {
    args.stack.push(new VarBool(lineNum, value));
}

std::string ExpValBool::toString() const {
    return (value ? "true" : "false");
}
