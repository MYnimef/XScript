//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

Compiler::Compiler() {

}

Compiler::~Compiler() {
    for (const auto& var: variables) {
        delete var.second;
    }

    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

void Compiler::execute(Node* tree) {
    auto child = tree->getChildren();

    for (auto node: tree->getChildren()) {
        execute(node);
    }

    tree->getExpression()->action(variables, stackVariablesId, stack);
}

const std::map<std::string, Variable*> &Compiler::getVariables() const {
    return variables;
}
