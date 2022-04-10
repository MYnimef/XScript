//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionValBool.h"
#include "VariableBool.h"

ExpressionValBool::ExpressionValBool(const std::string &value):
value(value == "true") {
    type = EXP_BOOL;
}

void ExpressionValBool::action(const CompilerArgs& args) const {

    args.stack.push(new VariableBool(value));
}

std::string ExpressionValBool::toString() const {
    return (value ? "true" : "false");
}
