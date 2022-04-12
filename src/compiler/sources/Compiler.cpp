//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

Compiler::Compiler(std::map<std::string, Node*>* functions) {
    this->functions.push_front(functions);
    variables = new std::map<std::string, Var*>();
}

Compiler::Compiler(
        const std::list<std::map<std::string, Node*>*>& functions,
        const std::list<std::map<std::string, Var*>*>& variablesGlobal
):
functions(functions),
variablesGlobal(variablesGlobal) {
    variables = new std::map<std::string, Var*>();
}

Compiler::~Compiler() {
    for (const auto& var: *variables) {
        delete var.second;
    }
    delete variables;
    cleanStack();
}

void Compiler::execute(const Node* tree) {
    for (auto node: tree->getChildren()) {
        executeChild(node);
        cleanStack();
    }

    tree->getExpression()->action(CompilerArgs(functions, variablesGlobal, variables, stack));
}

void Compiler::executeChild(const Node* tree) {
    for (auto node: tree->getChildren()) {
        executeChild(node);
    }

    tree->getExpression()->action(CompilerArgs(functions, variablesGlobal, variables, stack));
}

void Compiler::cleanStack() {
    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

const std::map<std::string, Var*>* Compiler::getVariables() const {
    return variables;
}

std::stack<Var*>& Compiler::getStack() {
    return stack;
}
