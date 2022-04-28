//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToList.h"
#include "VarList.h"

FuncToList::FuncToList():
ExpFuncCustom({ "arg1" }) {}

FuncToList::~FuncToList() = default;

void FuncToList::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = params.find("arg1")->second->getList();

    stack.push(new VarList(0, arg1));
}

std::string FuncToList::toString() const {
    return "list";
}
