//
// Created by Ivan Markov on 27.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncMap final: public ExpFuncCustom {
public:
    explicit FuncMap();

    ~FuncMap() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
