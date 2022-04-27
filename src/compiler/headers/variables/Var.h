//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>
#include <list>

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

    [[nodiscard]] virtual bool            getBool    ()    const;
    [[nodiscard]] virtual long long       getInteger ()    const;
    [[nodiscard]] virtual long double     getDouble  ()    const;
    [[nodiscard]] virtual std::string     getString  ()    const = 0;
    [[nodiscard]] virtual std::list<Var*> getList    ()    const = 0;

    [[nodiscard]] VarType getType() const;

private:
    const VarType type;

    [[nodiscard]] std::string getTypeName() const;

    [[noreturn]] void throwExcOperator(const std::string& op)                                const;
    [[noreturn]] void throwExcConvert(const std::string& value, const std::string& typeName) const;

protected:
    typedef Var super;
    const int lineNum;
};
