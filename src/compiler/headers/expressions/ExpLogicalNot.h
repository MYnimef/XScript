//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Exp.h"

class ExpLogicalNot final: public Exp {
public:
    explicit ExpLogicalNot(const int& lineNum);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
