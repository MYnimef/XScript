//
// Created by Ivan Markov on 28.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncAddToMap final: public ExpFuncCustom {
public:
    explicit FuncAddToMap();

    ~FuncAddToMap() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
