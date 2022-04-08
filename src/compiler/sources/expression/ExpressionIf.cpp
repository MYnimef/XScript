//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionIf.h"
#include "Compiler.h"

ExpressionIf::ExpressionIf(const Node* block):
block(block) {
    type = EXP_IF;
}

void ExpressionIf::action(
        std::list<std::map<std::string, Variable*>*> variablesGlobal,
        std::map<std::string, Variable*>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable*>& stack
        ) const {
    auto var = stack.top();
    stack.pop();

    if (var->getBool()) {
        variablesGlobal.push_front(variables);
        Compiler compiler(variablesGlobal);
        compiler.execute(block);
    }

    delete var;
}

std::string ExpressionIf::toString() const {
    return "if\n" + block->toString(1);
}
