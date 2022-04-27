//
// Created by Ivan Markov on 07.04.2022.
//

#include "ExpVarCall.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarBool.h"
#include "ExcExp.h"
#include "VarList.h"
#include "VarMap.h"

ExpVarCall::ExpVarCall(const int& lineNum, const std::string &value):
Exp(EXP_ID, lineNum),
id(value) {}

void ExpVarCall::action(const InterpreterArgs& args) const {
    for (auto scope: args.variablesGlobal) {
        if (callVariableFrom(scope, args.stack)) {
            return;
        }
    }

    if (!callVariableFrom(args.variables, args.stack)) {
        throw ExcExp("usage of undeclared var '" + id +  "'", lineNum);
    }
}

std::string ExpVarCall::toString() const {
    return id;
}

bool ExpVarCall::callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        auto var = it->second;
        switch (var->getType()) {
            case Var::BOOL_VAR:
                stack.push( new VarBool    ( lineNum, var->getBool    () ));
                return true;
            case Var::INTEGER_VAR:
                stack.push( new VarInteger ( lineNum, var->getInteger () ));
                return true;
            case Var::DOUBLE_VAR:
                stack.push( new VarDouble  ( lineNum, var->getDouble  () ));
                return true;
            case Var::STRING_VAR:
                stack.push( new VarString  ( lineNum, var->getString  () ));
                return true;
            case Var::LIST_VAR:
                stack.push( new VarList    ( lineNum, var->getList    () ));
                return true;
            case Var::MAP_VAR:
                stack.push( new VarMap     ( lineNum, var->getMap     () ));
                return true;
        }
    }

    return false;
}
