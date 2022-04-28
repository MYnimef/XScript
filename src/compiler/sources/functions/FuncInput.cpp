//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "FuncInput.h"
#include "VarString.h"

FuncInput::FuncInput():
ExpFuncCustom({}) {}

FuncInput::~FuncInput() = default;

void FuncInput::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    std::string value;
    std::cin >> value;
    stack.push(new VarString(0, value));
}

std::string FuncInput::toString() const {
    return "input";
}
