//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToString.h"
#include "VarString.h"

FuncToString::FuncToString():
ExpFuncCustom({ "arg1" }) {}

FuncToString::~FuncToString() = default;

void FuncToString::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = params.find("arg1")->second->getString();

    stack.push(new VarString(0, arg1));
}

std::string FuncToString::toString() const {
    return "string";
}
