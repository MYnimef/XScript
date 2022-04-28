//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpFuncCall.h"
#include "Interpreter.h"
#include "ExcExp.h"

ExpFuncCall::ExpFuncCall(const int& lineNum, const std::string &value, const std::list<Node*>& arguments):
Exp(EXP_FUNC_CALL, lineNum),
name(value),
arguments(arguments) {}

ExpFuncCall::~ExpFuncCall() {
    for (auto arg: arguments) {
        delete arg;
    }
}

void ExpFuncCall::action(const InterpreterArgs& args) const {
    for (auto functions: args.functions) {
        auto func = functions->find(name);
        if (func != functions->end()) {
            executeFunction(func->second, args);
            return;
        }
    }
    throw ExcExp("usage of undeclared func " + name, lineNum);
}

void ExpFuncCall::executeFunction(Node* func, const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Interpreter compiler(args.functions, args.variablesGlobal);
    for (auto node: arguments) {
        compiler.executeChild(node);
    }

    try {
        compiler.executeChild(func);
    } catch (const std::exception& ex) {
        throw ExcExp("error in function '" + name + "':\n" + ex.what(), lineNum);
    }

    if (!compiler.getStack().empty()) {
        args.stack.push(compiler.getStack().top());
        compiler.getStack().pop();
    }

    args.variablesGlobal.pop_front();
}

std::string ExpFuncCall::toString() const {
    return "function " + name;
}
