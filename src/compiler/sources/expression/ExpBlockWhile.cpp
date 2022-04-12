//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExpBlockWhile.h"
#include "Compiler.h"

ExpBlockWhile::ExpBlockWhile(
        const Node* blockCondition,
        const Node* blockExecute,
        std::map<std::string, Node*>* functions
):
blockCondition(blockCondition),
blockExecute(blockExecute),
functions(functions) {
    type = EXP_LOOP_WHILE;
}

ExpBlockWhile::~ExpBlockWhile() {
   delete blockCondition;
   delete blockExecute;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;
}

void ExpBlockWhile::action(const CompilerArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Compiler compilerCondition(args.functions, args.variablesGlobal);
    compilerCondition.execute(blockCondition);

    auto condition = compilerCondition.getStack().top();
    compilerCondition.getStack().pop();

    while (condition->getBool()) {
        args.functions.push_front(functions);

        Compiler compilerExecute(args.functions, args.variablesGlobal);
        compilerExecute.execute(blockExecute);

        args.functions.pop_front();

        compilerCondition.execute(blockCondition);
        delete condition;
        condition = compilerCondition.getStack().top();
        compilerCondition.getStack().pop();
    }

    args.variablesGlobal.pop_front();
    delete condition;
}

std::string ExpBlockWhile::toString() const {
    return "while\n        " + blockCondition->toString(2) + "\n        execute " + blockExecute->toString(2);
}
