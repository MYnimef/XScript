//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExpressionWhile.h"
#include "Compiler.h"

ExpressionWhile::ExpressionWhile(const Node *block):
block(block) {
    type = EXP_LOOP_WHILE;
}

void ExpressionWhile::action(const CompilerArgs &args) const {
    auto var = args.stack.top();
    args.stack.pop();

    while (var->getBool()) {
        args.variablesGlobal.push_front(args.variables);
        Compiler compiler(args.variablesGlobal);
        compiler.execute(block);
    }

    delete var;
}

std::string ExpressionWhile::toString() const {
    return "while";
}
