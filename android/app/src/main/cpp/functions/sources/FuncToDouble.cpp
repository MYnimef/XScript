//
// Created by Ivan Markov on 06.08.2022.
//

#include "FuncToDouble.h"
#include "VarDouble.h"

FuncToDouble::FuncToDouble():
        ExpFuncCustom({ "arg1" }) {}

FuncToDouble::~FuncToDouble() = default;

void FuncToDouble::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (long double) *params.find("arg1")->second;

    stack.push(new VarDouble(0, arg1));
}

std::string FuncToDouble::toString() const {
    return "float";
}