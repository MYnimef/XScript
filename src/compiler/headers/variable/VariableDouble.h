//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Variable.h"

class VariableDouble final: public Variable {
private:
    double value;

public:
    explicit VariableDouble(double value);

    Variable* operator + (const Variable&) const override;
    Variable* operator - (const Variable&) const override;
    Variable* operator * (const Variable&) const override;
    Variable* operator / (const Variable&) const override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] int getInteger() const override;
    [[nodiscard]] double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
};
