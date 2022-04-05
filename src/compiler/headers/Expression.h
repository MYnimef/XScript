//
// Created by Ivan Markov on 05.04.2022.
//

#pragma once

enum ExpressionType {
    VAR_DECLARATION,
    VAR_INITIALIZATION,
    VAR_ASSIGNMENT,

    VAR_INTEGER,
    VAR_DOUBLE,
    VAR_STRING,

    OP_SUM,
    OP_SUBTRACTION,
    OP_MULTIPLICATION,
    OP_DIVISION

};

class Expression final {
private:
    ExpressionType type;

};
