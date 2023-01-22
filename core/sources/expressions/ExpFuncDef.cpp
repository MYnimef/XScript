//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpFuncDef.h"
#include "Interpreter.h"

ExpFuncDef::ExpFuncDef(
        const int& lineNum,
        const std::string& value,
        const Node* body,
        std::map<std::string,Node*>* functions
):
Exp(EXP_FUNC_DEFINITION, lineNum),
name(value),
body(body),
functions(functions) {
}

ExpFuncDef::~ExpFuncDef() {
    delete body;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;
}

void ExpFuncDef::action(const InterpreterArgs &args) const {
    args.functions.push_front(functions);

    Interpreter compiler(args.functions);
    compiler.execute(body);

    args.functions.pop_front();
}

std::string ExpFuncDef::toString() const {
    return "";
}
