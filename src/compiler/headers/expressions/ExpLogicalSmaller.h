//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Exp.h"

class ExpLogicalSmaller final: public Exp {
public:
    explicit ExpLogicalSmaller(const int& lineNum);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
