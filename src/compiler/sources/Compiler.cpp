//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

void Compiler::execute(Node* tree) {
    auto child = tree->getChild();

    for (auto node: tree->getChild()) {
        execute(node);
    }

    tree->getToken()->action(variables, stackVariablesId, stack);
}

const std::map<std::string, Variable> &Compiler::getVariables() const {
    return variables;
}
