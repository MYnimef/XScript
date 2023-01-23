//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpFuncDef.h"
#include "Interpreter.h"

ExpFuncDef::ExpFuncDef(
        const int& lineNum,
        const std::string& value,
        const Node* body
):
Exp(EXP_FUNC_DEFINITION, lineNum),
name(value),
body(body) {
}

ExpFuncDef::~ExpFuncDef() {
    delete body;
}

void ExpFuncDef::action(const InterpreterArgs &args) const {
    Interpreter compiler(args.functions, args.variables);
    compiler.execute(body);
}

std::string ExpFuncDef::toString() const {
    return "";
}
