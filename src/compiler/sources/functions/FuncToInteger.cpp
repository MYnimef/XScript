//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToInteger.h"
#include "VarInteger.h"

FuncToInteger::FuncToInteger(const std::list<std::string> &args) : ExpFuncCustom(args) {

}

FuncToInteger::~FuncToInteger() {

}

void FuncToInteger::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    for (const auto& name: funcArgs) {
        stack.push(new VarInteger(0, params.find(name)->second->getInteger()));
    }
}

std::string FuncToInteger::toString() const {
    return "int";
}
