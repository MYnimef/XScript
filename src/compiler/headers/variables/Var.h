//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>
#include <list>

class Var {
protected:
    int lineNum;

public:
    explicit Var(const int& lineNum);
    virtual ~Var();

    virtual Var* operator + (const Var&) const = 0;
    virtual Var* operator - (const Var&) const = 0;
    virtual Var* operator * (const Var&) const = 0;
    virtual Var* operator / (const Var&) const = 0;

    Var* operator ! () const;
    Var* operator < (const Var&) const;
    Var* operator <= (const Var&) const;
    Var* operator > (const Var&) const;
    Var* operator >= (const Var&) const;
    Var* operator == (const Var&) const;
    Var* operator != (const Var&) const;
    Var* operator && (const Var&) const;
    Var* operator || (const Var&) const;

    [[nodiscard]] virtual bool getBool() const = 0;
    [[nodiscard]] virtual long long getInteger() const = 0;
    [[nodiscard]] virtual long double getDouble() const = 0;
    [[nodiscard]] virtual std::string getString() const = 0;
    [[nodiscard]] virtual std::list<Var*> getList() const = 0;

    enum VarType {
        BOOL_VAR,
        INTEGER_VAR,
        DOUBLE_VAR,
        STRING_VAR,
        LIST_VAR,
    };

    [[nodiscard]] VarType getType() const;

protected:
    VarType type;
};
