//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

Compiler::Compiler() {

}

Compiler::~Compiler() {
    for (auto var: variables) {
        delete var.second;
    }

    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

void Compiler::execute(Node* tree) {
    auto child = tree->getChild();

    for (auto node: tree->getChild()) {
        execute(node);
    }

    tree->getToken()->action(variables, stackVariablesId, stack);
}

const std::map<std::string, Variable*> &Compiler::getVariables() const {
    return variables;
}
