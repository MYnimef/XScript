//
// Created by Ivan Markov on 04.04.2022.
//

#include "Variable.h"

Variable::Variable(int val) {
    type = INTEGER_VAR;
    intVal = val;
}

Variable::Variable(double val) {
    type = DOUBLE_VAR;
    doubleVal = val;
}

Variable::Variable(std::string val) {
    type = STRING_VAR;
    stringVal = val;
}

Variable::~Variable() {

}

Variable Variable::operator + (const Variable& second) {
    if (type == INTEGER_VAR && second.type == INTEGER_VAR) {
        return Variable(intVal + second.intVal);
    } else if (type == INTEGER_VAR && second.type == DOUBLE_VAR) {
        return Variable(intVal + second.doubleVal);
    } else if (type == INTEGER_VAR && second.type == STRING_VAR) {
        return Variable(std::to_string(intVal) + second.stringVal);
    } else if (type == DOUBLE_VAR && second.type == INTEGER_VAR) {
        return Variable(doubleVal + second.intVal);
    } else if (type == DOUBLE_VAR && second.type == DOUBLE_VAR) {
        return Variable(doubleVal + second.doubleVal);
    } else if (type == DOUBLE_VAR && second.type == STRING_VAR) {
        return Variable(std::to_string(doubleVal) + second.stringVal);
    } else if (type == STRING_VAR && second.type == INTEGER_VAR) {
        return Variable(stringVal + std::to_string(second.intVal));
    } else if (type == STRING_VAR && second.type == DOUBLE_VAR) {
        return Variable(stringVal + std::to_string(second.doubleVal));
    } else {
        return Variable(stringVal + second.stringVal);
    }
}

Variable Variable::operator - (const Variable& second) {
    if (type == INTEGER_VAR && second.type == INTEGER_VAR) {
        return Variable(intVal - second.intVal);
    } else if (type == INTEGER_VAR && second.type == DOUBLE_VAR) {
        return Variable(intVal - second.doubleVal);
    } else if (type == DOUBLE_VAR && second.type == INTEGER_VAR) {
        return Variable(doubleVal - second.intVal);
    } else if (type == DOUBLE_VAR && second.type == DOUBLE_VAR) {
        return Variable(doubleVal - second.doubleVal);
    } else {
        throw std::overflow_error("wrong operand for type string");
    }
}

Variable Variable::operator * (const Variable& second) {
    if (type == INTEGER_VAR && second.type == INTEGER_VAR) {
        return Variable(intVal * second.intVal);
    } else if (type == INTEGER_VAR && second.type == DOUBLE_VAR) {
        return Variable(intVal * second.doubleVal);
    } else if (type == INTEGER_VAR && second.type == STRING_VAR) {
        std::string result;
        for (int i = 0; i < intVal; i++) {
            result += second.stringVal;
        }
        return Variable(result);
    } else if (type == DOUBLE_VAR && second.type == INTEGER_VAR) {
        return Variable(doubleVal * second.intVal);
    } else if (type == DOUBLE_VAR && second.type == DOUBLE_VAR) {
        return Variable(doubleVal * second.doubleVal);
    } else if (type == STRING_VAR && second.type == INTEGER_VAR) {
        std::string result;
        for (int i = 0; i < second.intVal; i++) {
            result += stringVal;
        }
        return Variable(result);
    } else {
        throw std::overflow_error("wrong operand for type string");
    }
}

Variable Variable::operator / (const Variable& second) {
    if (type == INTEGER_VAR && second.type == INTEGER_VAR) {
        return Variable(intVal / second.intVal);
    } else if (type == INTEGER_VAR && second.type == DOUBLE_VAR) {
        return Variable(intVal / second.doubleVal);
    } else if (type == DOUBLE_VAR && second.type == INTEGER_VAR) {
        return Variable(doubleVal / second.intVal);
    } else if (type == DOUBLE_VAR && second.type == DOUBLE_VAR) {
        return Variable(doubleVal / second.doubleVal);
    } else {
        throw std::overflow_error("wrong operand for type string");
    }
}

std::string Variable::toString() const {
    switch (type) {
        case INTEGER_VAR:
            return std::to_string(intVal);
        case DOUBLE_VAR:
            return std::to_string(doubleVal);
        case STRING_VAR:
            return stringVal;
    }
}

