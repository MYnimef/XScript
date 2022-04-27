//
// Created by Ivan Markov on 27.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncList final: public ExpFuncCustom {
public:
    explicit FuncList(const std::list<std::string>& args);

    ~FuncList() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
