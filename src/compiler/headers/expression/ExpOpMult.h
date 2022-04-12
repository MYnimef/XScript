//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Exp.h"

class ExpOpMult final: public Exp {
public:
    explicit ExpOpMult();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
