//
// Created by Ivan Markov on 27.04.2022.
//

#include "FuncList.h"
#include "VarList.h"

FuncList::FuncList(const std::list<std::string> &args):
ExpFuncCustom(args) {}

FuncList::~FuncList() = default;

void FuncList::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    stack.push(new VarList(0, {}));
}

std::string FuncList::toString() const {
    return "list";
}
