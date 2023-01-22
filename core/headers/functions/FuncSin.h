//
// Created by Ivan Markov on 22.01.2023.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncSin final: public ExpFuncCustom {
public:
    explicit FuncSin();

    ~FuncSin() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
