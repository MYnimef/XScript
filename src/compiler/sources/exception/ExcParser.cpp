//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExcParser.h"


ExcParser::ExcParser(const std::string &message) : runtime_error(
        "DSL Parser Exception :: " + message) {
}
