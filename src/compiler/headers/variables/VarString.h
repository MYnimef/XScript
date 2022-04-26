//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Var.h"

class VarString final: public Var {
private:
    const std::string value;

public:
    explicit VarString(const int& lineNum, const std::string& value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] long long getInteger() const override;
    [[nodiscard]] long double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
    [[nodiscard]] virtual std::list<Var*> getList() const override;
};
