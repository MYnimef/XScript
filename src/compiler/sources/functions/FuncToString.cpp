//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToString.h"
#include "VarString.h"

FuncToString::FuncToString(const std::list<std::string> &args) : ExpFuncCustom(args) {

}

FuncToString::~FuncToString() {

}

void FuncToString::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    for (const auto& name: funcArgs) {
        stack.push(new VarString(0, params.find(name)->second->getString()));
    }
}

std::string FuncToString::toString() const {
    return "string";
}
