//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpValBool.h"
#include "VarBool.h"

ExpValBool::ExpValBool(const std::string &value):
value(value == "true") {
    type = EXP_BOOL;
}

void ExpValBool::action(const CompilerArgs& args) const {

    args.stack.push(new VarBool(value));
}

std::string ExpValBool::toString() const {
    return (value ? "true" : "false");
}
