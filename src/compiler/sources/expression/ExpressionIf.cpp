//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionIf.h"
#include "Compiler.h"

ExpressionIf::ExpressionIf(const Node* blockCondition, const Node* blockExecute):
blockCondition(blockCondition),
blockExecute(blockExecute) {
    type = EXP_IF;
}

ExpressionIf::~ExpressionIf() {
    delete blockCondition;
    delete blockExecute;
}

void ExpressionIf::action(const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);
    Compiler compiler(args.variablesGlobal);
    compiler.execute(blockCondition);

    auto condition = compiler.getStack().top();
    compiler.getStack().pop();

    if (condition->getBool()) {
        compiler.execute(blockExecute);
    }

    args.variablesGlobal.pop_front();
    delete condition;
}

std::string ExpressionIf::toString() const {
    return "if\n        " + blockCondition->toString(2) + "\n        execute " + blockExecute->toString(2);
}
