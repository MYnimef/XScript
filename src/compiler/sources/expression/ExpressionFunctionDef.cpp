//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpressionFunctionDef.h"
#include "Compiler.h"

ExpressionFunctionDef::ExpressionFunctionDef(
        const std::string& value,
        const Node* body,
        std::map<std::string,Node*>* functions
):
name(name),
body(body),
functions(functions) {
    type = EXP_FUNC_DEFINITION;
}

void ExpressionFunctionDef::action(const CompilerArgs &args) const {
    args.variablesGlobal.push_front(args.variables);
    args.functions.push_front(functions);

    Compiler compiler(args.functions, args.variablesGlobal);
    compiler.execute(body);

    args.functions.pop_front();
    args.variablesGlobal.pop_front();
}

std::string ExpressionFunctionDef::toString() const {
    return "";
}
