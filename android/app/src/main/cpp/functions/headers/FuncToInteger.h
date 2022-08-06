//
// Created by Ivan Markov on 06.08.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncToInteger final: public ExpFuncCustom {
public:
    explicit FuncToInteger();

    ~FuncToInteger() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
