//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Exp.h"

class ExpLogicalGreater final: public Exp {
public:
    explicit ExpLogicalGreater(const int& lineNum);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
