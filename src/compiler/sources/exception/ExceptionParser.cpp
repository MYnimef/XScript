//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExceptionParser.h"


ExceptionParser::ExceptionParser(const std::string &message) : runtime_error(
        "DSL Parser Exception :: " + message) {
}
