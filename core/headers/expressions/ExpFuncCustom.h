//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"
#include "Node.h"

class ExpFuncCustom: public Exp {
private:
    const std::list<std::string> funcArgs;

public:
    explicit ExpFuncCustom(const std::list<std::string>& args);

    ~ExpFuncCustom() override;

    void action(const InterpreterArgs& args) const override;

    virtual void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const = 0;
};
