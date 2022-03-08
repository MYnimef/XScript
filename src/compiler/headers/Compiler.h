//
// Created by Ivan Markov on 08.03.2022.
//

#pragma once

#include <map>
#include <stack>
#include "Node.h"

class Compiler final {
private:
    std::map<std::string, int> integerVariables;
    std::map<std::string, double> doubleVariables;
    std::map<std::string, std::string> stringVariables;

    std::stack<int> integerStack;
    std::stack<double> doubleStack;
    std::stack<std::string> stringStack;

    template<class Type>
    bool checkVariable(std::map<std::string, Type>&, std::stack<Type>&, const Token&);

    template<class Type>
    void similarPlus(std::stack<Type>&);
    template<class Type>
    void similarMinus(std::stack<Type>&);
    template<class Type>
    void similarMux(std::stack<Type>&);
    template<class Type>
    void similarDivide(std::stack<Type>&);
    template<class Type>
    void similar(std::stack<Type>&, Type&, Type&);

public:
    void execute(Node*);

    [[nodiscard]] const std::map<std::string, int>& getIntegerVariables() const;
    [[nodiscard]] const std::map<std::string, double>& getDoubleVariables() const;
    [[nodiscard]] const std::map<std::string, std::string>& getStringVariables() const;
};