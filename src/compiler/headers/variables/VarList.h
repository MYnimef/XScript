//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Var.h"

class VarList final: public Var {
private:
    std::list<Var*> value;

public:
    explicit VarList(std::list<Var*> value);

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
