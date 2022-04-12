//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

Compiler::Compiler(std::map<std::string, Node*>* functions) {
    this->functions.push_front(functions);
    variables = new std::map<std::string, Variable*>();
}

Compiler::Compiler(
        const std::list<std::map<std::string, Node*>*>& functions,
        const std::list<std::map<std::string, Variable*>*>& variablesGlobal
):
functions(functions),
variablesGlobal(variablesGlobal) {
    variables = new std::map<std::string, Variable*>();
}

Compiler::~Compiler() {
    for (const auto& var: *variables) {
        delete var.second;
    }
    delete variables;

    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

void Compiler::execute(const Node* tree) {
    auto child = tree->getChildren();

    for (auto node: tree->getChildren()) {
        execute(node);
    }

    tree->getExpression()->action(CompilerArgs(functions, variablesGlobal, variables, stackVariablesId, stack));
}

const std::map<std::string, Variable*>* Compiler::getVariables() const {
    return variables;
}

std::stack<Variable*>& Compiler::getStack() {
    return stack;
}
