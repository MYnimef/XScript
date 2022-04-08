//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

Compiler::Compiler() {
    variables = new std::map<std::string, Variable*>();
}

Compiler::Compiler(const std::list<std::map<std::string, Variable*>*>& variablesGlobal):
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

    tree->getExpression()->action(variablesGlobal, variables, stackVariablesId, stack);
}

const std::map<std::string, Variable*>* Compiler::getVariables() const {
    return variables;
}
