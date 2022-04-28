//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "FuncPrint.h"

FuncPrint::FuncPrint():
ExpFuncCustom({ "arg1" }) {}

FuncPrint::~FuncPrint() = default;

void FuncPrint::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (std::string) *params.find("arg1")->second;

    std::cout << arg1;
}

std::string FuncPrint::toString() const {
    return "print";
}
