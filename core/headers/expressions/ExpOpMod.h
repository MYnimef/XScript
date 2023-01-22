//
// Created by Ivan Markov on 22.01.2023.
//

#pragma once

#include "Exp.h"

class ExpOpMod final: public Exp {
public:
    explicit ExpOpMod(const int& lineNum);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
