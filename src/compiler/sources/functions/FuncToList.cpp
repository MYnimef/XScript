//
// Created by Ivan Markov on 12.04.2022.
//

#include "FuncToList.h"
#include "VarList.h"

FuncToList::FuncToList(const std::list<std::string> &args) : ExpFuncCustom(args) {

}

FuncToList::~FuncToList() {

}

void FuncToList::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    for (const auto& name: funcArgs) {
        stack.push(new VarList(0, params.find(name)->second->getList()));
    }
}

std::string FuncToList::toString() const {
    return "list";
}
