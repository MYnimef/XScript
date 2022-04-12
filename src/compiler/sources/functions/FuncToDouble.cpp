//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToDouble.h"
#include "VarDouble.h"

FuncToDouble::FuncToDouble(const std::list<std::string> &args) : ExpFuncCustom(args) {

}

FuncToDouble::~FuncToDouble() {

}

void FuncToDouble::action(const std::map<std::string, Var *> &params, std::stack<Var *> &stack) const {
    for (const auto& name: funcArgs) {
        stack.push(new VarDouble(0, params.find(name)->second->getDouble()));
    }
}

std::string FuncToDouble::toString() const {
    return "float";
}
