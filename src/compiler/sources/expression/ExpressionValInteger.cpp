//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionValInteger.h"
#include "VariableInteger.h"

ExpressionValInteger::ExpressionValInteger(const long long value):
value(value) {
    type = EXP_INTEGER;
}

ExpressionValInteger::ExpressionValInteger(const std::string& value):
value(std::stoll(value)) {
    type = EXP_INTEGER;
}

void ExpressionValInteger::action(const CompilerArgs& args) const {

    args.stack.push(new VariableInteger(value));
}

std::string ExpressionValInteger::toString() const {
    return std::to_string(value);
}
