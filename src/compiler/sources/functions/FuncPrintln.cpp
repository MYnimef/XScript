//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "FuncPrintln.h"

FuncPrintln::FuncPrintln(const std::list<std::string> &args):
ExpFuncCustom(args) {

}

FuncPrintln::~FuncPrintln() {

}

void FuncPrintln::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    for (const auto& name: funcArgs) {
        std::cout << std::endl << params.find(name)->second->getString();
    }
}

std::string FuncPrintln::toString() const {
    return "println";
}
