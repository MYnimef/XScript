//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToInteger.h"
#include "VarInteger.h"

FuncToInteger::FuncToInteger(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncToInteger::~FuncToInteger() = default;

void FuncToInteger::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    const auto& arg1 = params.find("arg1")->second->getInteger();

    stack.push(new VarInteger(0, arg1));
}

std::string FuncToInteger::toString() const {
    return "int";
}
