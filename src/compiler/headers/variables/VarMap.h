//
// Created by Ivan Markov on 27.04.2022.
//

#pragma once

#include <map>
#include "Var.h"

class VarMap final: public Var {
private:
    const std::map<Var*, Var*> value;

public:
    explicit VarMap(const int& lineNum, const std::list<Var*>& value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] long long getInteger() const override;
    [[nodiscard]] long double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
    [[nodiscard]] std::list<Var*> getList() const override;
};
