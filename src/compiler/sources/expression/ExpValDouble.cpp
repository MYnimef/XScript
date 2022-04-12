//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpValDouble.h"
#include "VarDouble.h"

ExpValDouble::ExpValDouble(const std::string& value):
value(std::stold(value)) {
    type = EXP_DOUBLE;
}

void ExpValDouble::action(const CompilerArgs& args) const {

    args.stack.push(new VarDouble(value));
}

std::string ExpValDouble::toString() const {
    return std::to_string(value);
}
