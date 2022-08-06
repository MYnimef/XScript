//
// Created by Ivan Markov on 06.08.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncToString final: public ExpFuncCustom {
public:
    explicit FuncToString();

    ~FuncToString() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
