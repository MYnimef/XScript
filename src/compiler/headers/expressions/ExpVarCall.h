//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"

class ExpVarCall final: public Exp {
private:
    std::string id;

    bool callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const;

public:
    explicit ExpVarCall(const int& lineNum, const std::string& value);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
