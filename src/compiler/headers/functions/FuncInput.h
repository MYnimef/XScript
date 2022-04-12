//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncInput final: public ExpFuncCustom {
public:
    explicit FuncInput(const std::list<std::string>& args);

    ~FuncInput() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
