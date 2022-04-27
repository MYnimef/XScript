//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToDouble.h"
#include "VarDouble.h"

FuncToDouble::FuncToDouble(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncToDouble::~FuncToDouble() = default;

void FuncToDouble::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = params.find("arg1")->second->getDouble();

    stack.push(new VarDouble(0, arg1));
}

std::string FuncToDouble::toString() const {
    return "float";
}
