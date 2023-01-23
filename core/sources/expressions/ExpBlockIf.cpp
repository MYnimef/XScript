//
// Created by Ivan Markov on 08.04.2022.
//

#include "ExpBlockIf.h"
#include "Interpreter.h"

ExpBlockIf::ExpBlockIf(
        const int& lineNum,
        const std::list<Node*>* blockConditions,
        const std::list<Node*>* blockExecutes,
        const std::list<std::map<std::string, Node*>*>* functions
):
Exp(EXP_IF, lineNum),
blockConditions(blockConditions),
blockExecutes(blockExecutes),
functions(functions) {}

ExpBlockIf::~ExpBlockIf() {
    for (auto block: *blockConditions) {
        delete block;
    }
    delete blockConditions;
    for (auto block: *blockExecutes) {
        delete block;
    }
    delete blockExecutes;
    for (auto funcBlock: *functions) {
        for (const auto &func: *funcBlock) {
            delete func.second;
        }
        delete funcBlock;
    }
    delete functions;
}

void ExpBlockIf::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    auto it1 = blockConditions->begin();
    auto it2 = blockExecutes->begin();
    auto it3 = functions->begin();
    for (; it1 != blockConditions->end(); it1++, it2++, it3++) {
        Interpreter compilerCondition(args.functions, args.variablesGlobal);
        compilerCondition.executeChild(*it1);
        auto condition = compilerCondition.getStack().top();
        compilerCondition.getStack().pop();
        bool flag = (bool) *condition;
        delete condition;

        if (flag) {
            args.functions.push_front(*it3);
            Interpreter compilerBlock(args.functions, args.variablesGlobal);
            compilerBlock.execute(*it2);
            args.functions.pop_front();
            args.variablesGlobal.pop_front();
            return;
        }
    }

    if (it2 != blockExecutes->end()) {
        args.functions.push_front(*it3);
        Interpreter compilerBlock(args.functions, args.variablesGlobal);
        compilerBlock.execute(*it2);
        args.functions.pop_front();
    }
    args.variablesGlobal.pop_front();
}

std::string ExpBlockIf::toString() const {
    return "if\n        ";
}
