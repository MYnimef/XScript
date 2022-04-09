//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionIf.h"
#include "Compiler.h"

ExpressionIf::ExpressionIf(const Node* block):
block(block) {
    type = EXP_IF;
}

void ExpressionIf::action(const CompilerArgs& args) const {
    auto var = args.stack.top();
    args.stack.pop();

    if (var->getBool()) {
        args.variablesGlobal.push_front(args.variables);
        Compiler compiler(args.variablesGlobal);
        compiler.execute(block);
    }

    delete var;
}

std::string ExpressionIf::toString() const {
    return "if\n    " + block->toString(1);
}
