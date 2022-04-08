//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Variable.h"

class VariableInteger final: public Variable {
private:
    int value;

public:
    explicit VariableInteger(int value);

    Variable* operator + (const Variable&) override;
    Variable* operator - (const Variable&) override;
    Variable* operator * (const Variable&) override;
    Variable* operator / (const Variable&) override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] int getInteger() const override;
    [[nodiscard]] double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
};
