//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Var.h"

class VarBool final: public Var {
private:
    bool value;

public:
    explicit VarBool(bool value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] long long getInteger() const override;
    [[nodiscard]] long double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
};