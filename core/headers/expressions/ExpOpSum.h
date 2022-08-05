//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Exp.h"

class ExpOpSum final: public Exp {
public:
    explicit ExpOpSum(const int& lineNum);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
