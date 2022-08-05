//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "../headers/FuncPrintln.h"

FuncPrintln::FuncPrintln():
ExpFuncCustom({ "arg1" }) {}

FuncPrintln::~FuncPrintln() = default;

void FuncPrintln::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (std::string) *params.find("arg1")->second;

    std::cout << std::endl << arg1;
}

std::string FuncPrintln::toString() const {
    return "println";
}
