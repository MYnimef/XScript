//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToBool.h"
#include "VarBool.h"

FuncToBool::FuncToBool(const std::list<std::string> &args) : ExpFuncCustom(args) {

}

FuncToBool::~FuncToBool() {

}

void FuncToBool::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    for (const auto& name: funcArgs) {
        stack.push(new VarBool(0, params.find(name)->second->getBool()));
    }
}

std::string FuncToBool::toString() const {
    return "bool";
}
