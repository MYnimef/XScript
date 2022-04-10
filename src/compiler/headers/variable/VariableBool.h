//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Variable.h"

class VariableBool final: public Variable {
private:
    bool value;

public:
    explicit VariableBool(bool value);

    Variable* operator + (const Variable&) const override;
    Variable* operator - (const Variable&) const override;
    Variable* operator * (const Variable&) const override;
    Variable* operator / (const Variable&) const override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] long long getInteger() const override;
    [[nodiscard]] long double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
};
