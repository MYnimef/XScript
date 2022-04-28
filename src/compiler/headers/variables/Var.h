//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>
#include <list>
#include <map>

class Var {
public:
    enum VarType {
        BOOL_VAR,
        INTEGER_VAR,
        DOUBLE_VAR,
        STRING_VAR,
        LIST_VAR,
        MAP_VAR,
    };

    explicit Var(const int& lineNum, const VarType& type);
    virtual ~Var();

    virtual Var* operator + (const Var&) const;
    virtual Var* operator - (const Var&) const;
    virtual Var* operator * (const Var&) const;
    virtual Var* operator / (const Var&) const;

    Var* operator !  (          ) const;
    Var* operator <  (const Var&) const;
    Var* operator <= (const Var&) const;
    Var* operator >  (const Var&) const;
    Var* operator >= (const Var&) const;
    Var* operator == (const Var&) const;
    Var* operator != (const Var&) const;
    Var* operator && (const Var&) const;
    Var* operator || (const Var&) const;

    [[nodiscard]] virtual explicit operator bool            () const;
    [[nodiscard]] virtual explicit operator long long       () const;
    [[nodiscard]] virtual explicit operator long double     () const;
    [[nodiscard]] virtual explicit operator std::string     () const = 0;
    [[nodiscard]] virtual explicit operator std::list<Var*> () const;
    [[nodiscard]] virtual explicit operator std::map<Var*, Var*> () const;

    [[nodiscard]] VarType getType() const;

    [[nodiscard]] virtual Var* copy(const int& lineNum) const = 0;

private:
    const VarType type;

    [[nodiscard]] std::string getTypeName() const;

    [[noreturn]] void throwExcOperator (const std::string& op)                                 const;
    [[noreturn]] void throwExcConvert  (const std::string& value, const std::string& typeName) const;

protected:
    typedef Var super;
    const int lineNum;
};
