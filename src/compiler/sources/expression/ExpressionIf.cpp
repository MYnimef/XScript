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

void ExpressionIf::action(const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);
    Compiler compiler(args.variablesGlobal);
    compiler.execute(blockCondition);

    auto condition = compiler.getStack().top();
    compiler.getStack().pop();

    if (condition->getBool()) {
        compiler.execute(blockExecute);
    }

    delete condition;
}

std::string ExpressionIf::toString() const {
    return "\n    " + blockCondition->toString(1) + "\n    " + blockExecute->toString(1) + "\n    endif";
}
