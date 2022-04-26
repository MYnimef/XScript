//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Exp.h"

class ExpValInteger final: public Exp {
private:
    long long value;

public:
    explicit ExpValInteger(const int& lineNum, long long value);
    explicit ExpValInteger(const int& lineNum, const std::string& value);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
