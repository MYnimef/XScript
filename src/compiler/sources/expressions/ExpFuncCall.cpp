//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpFuncCall.h"
#include "Compiler.h"

ExpFuncCall::ExpFuncCall(const std::string &value, const std::list<Node*>& arguments):
name(value),
arguments(arguments) {
    type = EXP_FUNC_CALL;
}

ExpFuncCall::~ExpFuncCall() {
    for (auto arg: arguments) {
        delete arg;
    }
}

void ExpFuncCall::action(const CompilerArgs& args) const {
    for (auto functions: args.functions) {
        auto func = functions->find(name);
        if (func != functions->end()) {
            executeFunction(func->second, args);
            return;
        }
    }
    throw std::overflow_error("usage of undeclared func");
}

void ExpFuncCall::executeFunction(Node* func, const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Compiler compiler(args.functions, args.variablesGlobal);
    for (const auto node: arguments) {
        compiler.execute(node);
    }
    compiler.execute(func);

    args.variablesGlobal.pop_front();
}

std::string ExpFuncCall::toString() const {
    return "function " + name;
}
