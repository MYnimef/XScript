//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExpFuncCustom.h"

ExpFuncCustom::ExpFuncCustom(const std::list<std::string>& args):
funcArgs(args) {
    type = EXP_FUNC_DEFINITION;
}

ExpFuncCustom::~ExpFuncCustom() {

}

void ExpFuncCustom::action(const CompilerArgs &args) const {
    std::map<std::string, Var*> params;
    for (const auto& name: funcArgs) {
        params.insert_or_assign(name, args.stack.top());
        args.stack.pop();
    }
    action(params);
}
