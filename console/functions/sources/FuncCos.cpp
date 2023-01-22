//
// Created by Ivan Markov on 22.01.2023.
//

#include <cmath>
#include "FuncCos.h"
#include "VarDouble.h"

FuncCos::FuncCos():
        ExpFuncCustom({ "arg1" }) {}

FuncCos::~FuncCos() = default;

void FuncCos::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (long double) *params.find("arg1")->second;

    stack.push(new VarDouble(0, cos(arg1)));
}

std::string FuncCos::toString() const {
    return "cos";
}
