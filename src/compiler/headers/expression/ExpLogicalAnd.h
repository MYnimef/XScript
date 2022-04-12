//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Exp.h"

class ExpLogicalAnd final: public Exp {
public:
    explicit ExpLogicalAnd();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
