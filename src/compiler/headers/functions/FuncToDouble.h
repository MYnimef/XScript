//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncToDouble final: public ExpFuncCustom {
public:
    explicit FuncToDouble();

    ~FuncToDouble() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
