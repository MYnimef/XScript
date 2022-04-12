//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Exp.h"

class ExpLogicalSmallerOrEqual final: public Exp {
public:
    explicit ExpLogicalSmallerOrEqual();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
