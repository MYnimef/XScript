//
// Created by Ivan Markov on 12.04.2022.
//

#include <iostream>
#include "FuncPrint.h"

FuncPrint::FuncPrint(const std::list<std::string> &args):
ExpFuncCustom(args) {

}

FuncPrint::~FuncPrint() {

}

void FuncPrint::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    for (const auto& name: funcArgs) {
        std::cout << params.find(name)->second->getString();
    }
}

std::string FuncPrint::toString() const {
    return "print";
}
