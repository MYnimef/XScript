//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncPrint final: public ExpFuncCustom {
public:
    explicit FuncPrint(const std::list<std::string>& args);

    ~FuncPrint() override;

    void action(const std::map<std::string, Var*>& params) const override;

    [[nodiscard]] std::string toString() const override;
};
