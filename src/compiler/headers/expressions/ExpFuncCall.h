//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"
#include "Node.h"

class ExpFuncCall final: public Exp {
private:
    const std::string name;
    const std::list<Node*> arguments;

    void executeFunction(Node* func, const CompilerArgs& args) const;

public:
    explicit ExpFuncCall(const int& lineNum, const std::string& value, const std::list<Node*>& arguments);
    ~ExpFuncCall() override;

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
