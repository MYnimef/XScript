//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpressionFunctionCall.h"
#include "Compiler.h"

ExpressionFunctionCall::ExpressionFunctionCall(const std::string &value, const std::list<Node*>& arguments):
name(value),
arguments(arguments) {
    type = EXP_FUNC;
}

void ExpressionFunctionCall::action(const CompilerArgs& args) const {
    for (auto functions: args.functions) {
        auto func = functions->find(name);
        if (func != functions->end()) {
            executeFunction(func->second, args);
            return;
        }
    }
    throw std::overflow_error("usage of undeclared func");
}

void ExpressionFunctionCall::executeFunction(Node* func, const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Compiler compiler(args.functions, args.variablesGlobal);
    for (const auto node: arguments) {
        compiler.execute(node);
    }
    compiler.execute(func);

    args.variablesGlobal.pop_front();
}

std::string ExpressionFunctionCall::toString() const {
    return "function " + name;
}
