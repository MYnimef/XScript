//
// Created by Ivan Markov on 28.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncClearConsole final: public ExpFuncCustom {
public:
    explicit FuncClearConsole();

    ~FuncClearConsole() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
