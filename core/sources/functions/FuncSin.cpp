//
// Created by Ivan Markov on 22.01.2023.
//

#include <cmath>
#include "FuncSin.h"
#include "VarDouble.h"

FuncSin::FuncSin():
        ExpFuncCustom({ "arg1" }) {}

FuncSin::~FuncSin() = default;

void FuncSin::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (long double) *params.find("arg1")->second;

    stack.push(new VarDouble(0,  sin(arg1)));
}

std::string FuncSin::toString() const {
    return "sin";
}