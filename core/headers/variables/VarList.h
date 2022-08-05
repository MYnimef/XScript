//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Var.h"

class VarList final: public Var {
private:
    const std::list<Var*> value;

public:
    explicit VarList(const int& lineNum, const std::list<Var*>& value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;

    [[nodiscard]] explicit operator bool            () const override;
    [[nodiscard]] explicit operator long long       () const override;
    [[nodiscard]] explicit operator long double     () const override;
    [[nodiscard]] explicit operator std::string     () const override;
    [[nodiscard]] explicit operator std::list<Var*> () const override;

    [[nodiscard]] Var* copy(const int& lineNum) const override;
};
