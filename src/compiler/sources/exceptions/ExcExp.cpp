//
// Created by Ivan Markov on 12.04.2022.
//

#include "ExcExp.h"

ExcExp::ExcExp(const std::string &message) : runtime_error(
        "DSL Expression Exception :: " + message) {

}
