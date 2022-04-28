//
// Created by Ivan Markov on 28.04.2022.
//

#include "FuncClearConsole.h"

FuncClearConsole::FuncClearConsole():
ExpFuncCustom({}) {}

FuncClearConsole::~FuncClearConsole() = default;

void FuncClearConsole::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
#if defined _WIN32
    std::system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::system("clear");
#elif defined (__APPLE__)
    std::system("clear");
#endif
}

std::string FuncClearConsole::toString() const {
    return "clc";
}
