//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Exp.h"

class ExpOpSum final: public Exp {
public:
    explicit ExpOpSum();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
