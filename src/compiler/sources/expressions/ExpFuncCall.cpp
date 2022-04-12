//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpFuncCall.h"
#include "Compiler.h"
#include "ExcExp.h"

ExpFuncCall::ExpFuncCall(const int& lineNum, const std::string &value, const std::list<Node*>& arguments):
Exp(EXP_FUNC_CALL, lineNum),
name(value),
arguments(arguments) {
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
    throw ExcExp("usage of undeclared func " + name + " at line " + std::to_string(lineNum));
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
