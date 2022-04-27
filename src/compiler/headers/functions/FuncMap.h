//
// Created by Ivan Markov on 27.04.2022.
//

#pragma once


#include "ExpFuncCustom.h"

class FuncMap final: public ExpFuncCustom {
public:
    explicit FuncMap(const std::list<std::string>& args);

    ~FuncMap() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    [[nodiscard]] std::string toString() const override;
};
