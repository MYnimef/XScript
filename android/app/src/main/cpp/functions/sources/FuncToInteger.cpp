//
// Created by Ivan Markov on 06.08.2022.
//

#include "FuncToInteger.h"
#include "VarInteger.h"

FuncToInteger::FuncToInteger():
        ExpFuncCustom({ "arg1" }) {}

FuncToInteger::~FuncToInteger() = default;

void FuncToInteger::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    const auto& arg1 = (long long) *params.find("arg1")->second;

    stack.push(new VarInteger(0, arg1));
}

std::string FuncToInteger::toString() const {
    return "int";
}