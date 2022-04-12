//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncToList final: public ExpFuncCustom {
public:
    explicit FuncToList(const std::list<std::string>& args);

    ~FuncToList() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
