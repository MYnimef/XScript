//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToBool.h"
#include "VarBool.h"

FuncToBool::FuncToBool(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncToBool::~FuncToBool() = default;

void FuncToBool::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    const auto& arg1 = params.find("arg1")->second->getBool();

    stack.push(new VarBool(0, arg1));
}

std::string FuncToBool::toString() const {
    return "bool";
}
