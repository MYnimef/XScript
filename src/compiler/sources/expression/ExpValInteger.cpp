//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValInteger.h"
#include "VarInteger.h"

ExpValInteger::ExpValInteger(const long long value):
value(value) {
    type = EXP_INTEGER;
}

ExpValInteger::ExpValInteger(const std::string& value):
value(std::stoll(value)) {
    type = EXP_INTEGER;
}

void ExpValInteger::action(const CompilerArgs& args) const {

    args.stack.push(new VarInteger(value));
}

std::string ExpValInteger::toString() const {
    return std::to_string(value);
}
