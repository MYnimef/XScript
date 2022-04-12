//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValString.h"
#include "VarString.h"

ExpValString::ExpValString(const std::string& value) {
    this->value = value.substr(1, value.size() - 2);
    type = EXP_STRING;
}

void ExpValString::action(const CompilerArgs& args) const {

    args.stack.push(new VarString(value));
}

std::string ExpValString::toString() const {
    return value;
}
