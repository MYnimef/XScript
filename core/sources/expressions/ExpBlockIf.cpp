//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpBlockIf.h"
#include "Interpreter.h"

ExpBlockIf::ExpBlockIf(
        const int& lineNum,
        const std::list<Node*>* blockConditions,
        const std::list<Node*>* blockExecutes
):
Exp(EXP_IF, lineNum),
blockConditions(blockConditions),
blockExecutes(blockExecutes) {}

ExpBlockIf::~ExpBlockIf() {
    for (auto block: *blockConditions) {
        delete block;
    }
    delete blockConditions;
    for (auto block: *blockExecutes) {
        delete block;
    }
    delete blockExecutes;
}

void ExpBlockIf::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    auto it1 = blockConditions->begin();
    auto it2 = blockExecutes->begin();
    for (; it1 != blockConditions->end(); it1++, it2++) {
        Interpreter compilerCondition(args.functions, args.variablesGlobal);
        compilerCondition.executeChild(*it1);
        auto condition = compilerCondition.getStack().top();
        compilerCondition.getStack().pop();
        bool flag = (bool) *condition;
        delete condition;

        if (flag) {
            Interpreter compilerBlock(args.functions, args.variablesGlobal);
            compilerBlock.execute(*it2);
            args.variablesGlobal.pop_front();
            return;
        }
    }

    if (it2 != blockExecutes->end()) {
        Interpreter compilerBlock(args.functions, args.variablesGlobal);
        compilerBlock.execute(*it2);
    }
    args.variablesGlobal.pop_front();
}

std::string ExpBlockIf::toString() const {
    return "if\n        ";
}
