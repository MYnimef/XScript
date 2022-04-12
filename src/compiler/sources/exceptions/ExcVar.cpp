//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExcVar.h"

ExcVar::ExcVar(const std::string &message) : runtime_error(
        "DSL Variable Exception :: " + message) {

}
