//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpressionIf.h"
#include "Compiler.h"

ExpressionIf::ExpressionIf(
        const Node* blockCondition,
        const Node* blockExecute,
        std::map<std::string, Node*>* functions
):
blockCondition(blockCondition),
blockExecute(blockExecute),
functions(functions) {
    type = EXP_IF;
}

ExpressionIf::~ExpressionIf() {
    delete blockCondition;
    delete blockExecute;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;
}

void ExpressionIf::action(const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Compiler compilerCondition(args.functions, args.variablesGlobal);
    compilerCondition.execute(blockCondition);

    auto condition = compilerCondition.getStack().top();
    compilerCondition.getStack().pop();

    if (condition->getBool()) {
        args.functions.push_front(functions);

        Compiler compilerBlock(args.functions, args.variablesGlobal);
        compilerBlock.execute(blockExecute);

        args.functions.pop_front();
    }

    args.variablesGlobal.pop_front();
    delete condition;
}

std::string ExpressionIf::toString() const {
    return "if\n        " + blockCondition->toString(2) + "\n        execute " + blockExecute->toString(2);
}
