//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpressionFunctionDef.h"

ExpressionFunctionDef::ExpressionFunctionDef(const std::string &value, const std::list<Node*>& arguments, const Node* body):
name(name),
arguments(arguments),
body(body) {
    type = EXP_FUNC_DEFINITION;
}

void ExpressionFunctionDef::action(const CompilerArgs &args) const {

}

std::string ExpressionFunctionDef::toString() const {
    return "";
}
