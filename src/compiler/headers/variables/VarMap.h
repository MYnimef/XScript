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
    explicit VarMap(const int& lineNum, const std::map<Var*, Var*>& value);

    Var* operator + (const Var& second) const override;
    Var* operator - (const Var& second) const override;
    Var* operator * (const Var& second) const override;
    Var* operator / (const Var& second) const override;

    [[nodiscard]] bool            getBool    () const override;
    [[nodiscard]] long long       getInteger () const override;
    [[nodiscard]] long double     getDouble  () const override;
    [[nodiscard]] std::string     getString  () const override;
    [[nodiscard]] std::list<Var*> getList    () const override;
    [[nodiscard]] std::map<Var*, Var*> getMap() const override;
};
