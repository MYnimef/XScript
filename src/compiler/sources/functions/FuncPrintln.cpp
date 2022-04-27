//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "FuncPrintln.h"

FuncPrintln::FuncPrintln(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncPrintln::~FuncPrintln() = default;

void FuncPrintln::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = params.find("arg1")->second->getString();

    std::cout << std::endl << arg1;
}

std::string FuncPrintln::toString() const {
    return "println";
}
