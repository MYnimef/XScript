//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExpFuncCustom.h"

ExpFuncCustom::ExpFuncCustom(const std::list<std::string>& args):
Exp(EXP_FUNC_DEFINITION, 0),
funcArgs(args) {}

ExpFuncCustom::~ExpFuncCustom() {

}

void ExpFuncCustom::action(const InterpreterArgs &args) const {
    std::map<std::string, Var*> params;
    for (const auto& name: funcArgs) {
        params.insert_or_assign(name, args.stack.top());
        args.stack.pop();
    }
    action(params, args.stack);
}
