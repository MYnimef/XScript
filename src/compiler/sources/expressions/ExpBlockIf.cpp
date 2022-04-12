//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpBlockIf.h"
#include "Compiler.h"

ExpBlockIf::ExpBlockIf(
        const int& lineNum,
        const Node* blockCondition,
        const Node* blockExecute,
        std::map<std::string, Node*>* functions
):
Exp(EXP_IF, lineNum),
blockCondition(blockCondition),
blockExecute(blockExecute),
functions(functions) {
}

ExpBlockIf::~ExpBlockIf() {
    delete blockCondition;
    delete blockExecute;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;
}

void ExpBlockIf::action(const CompilerArgs& args) const {
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

std::string ExpBlockIf::toString() const {
    return "if\n        " + blockCondition->toString(2) + "\n        execute " + blockExecute->toString(2);
}
