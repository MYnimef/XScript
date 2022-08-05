//
// Created by Ivan Markov on 12.04.2022.
//

#include "Exc.h"

Exc::Exc(const std::string& type, const std::string &message, const int &lineNum):
runtime_error(
        type + " Exception :: " + message + (lineNum == 0 ? "" : " at line " + std::to_string(lineNum))
        ) {}
