//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>
//#include <list>

class Variable {
public:
    explicit Variable();
    virtual ~Variable();

    virtual Variable* operator + (const Variable&) const = 0;
    virtual Variable* operator - (const Variable&) const = 0;
    virtual Variable* operator * (const Variable&) const = 0;
    virtual Variable* operator / (const Variable&) const = 0;

    Variable* operator ! () const;
    Variable* operator < (const Variable&) const;
    Variable* operator <= (const Variable&) const;
    Variable* operator > (const Variable&) const;
    Variable* operator >= (const Variable&) const;
    Variable* operator == (const Variable&) const;
    Variable* operator != (const Variable&) const;
    Variable* operator && (const Variable&) const;
    Variable* operator || (const Variable&) const;

    [[nodiscard]] virtual bool getBool() const = 0;
    [[nodiscard]] virtual int getInteger() const = 0;
    [[nodiscard]] virtual double getDouble() const = 0;
    [[nodiscard]] virtual std::string getString() const = 0;
    //[[nodiscard]] virtual std::list<Variable*> getList() const = 0;

    enum VarType {
        BOOL_VAR,
        INTEGER_VAR,
        DOUBLE_VAR,
        STRING_VAR,
        //LIST_VAR,
    };

    [[nodiscard]] VarType getType() const;

protected:
    VarType type;
};
