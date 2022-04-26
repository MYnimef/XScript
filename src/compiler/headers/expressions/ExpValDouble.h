//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Exp.h"

class ExpValDouble final: public Exp {
private:
    long double value;

public:
    explicit ExpValDouble(const int& lineNum, const std::string& value);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
