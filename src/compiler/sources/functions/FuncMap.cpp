//
// Created by Ivan Markov on 27.04.2022.
//

#include "FuncMap.h"
#include "VarMap.h"

FuncMap::FuncMap(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncMap::~FuncMap() = default;

void FuncMap::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    stack.push(new VarMap(0, {}));
}

std::string FuncMap::toString() const {
    return "map";
}
