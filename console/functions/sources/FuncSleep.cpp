//
// Created by Ivan Markov on 27.04.2022.
//

#include <chrono>
#include <thread>
#include "../headers/FuncSleep.h"

FuncSleep::FuncSleep():
ExpFuncCustom({ "arg1" }) {}

FuncSleep::~FuncSleep() = default;

void FuncSleep::action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const {
    const auto& arg1 = (long long) *params.find("arg1")->second;

    std::this_thread::sleep_for(std::chrono::milliseconds(arg1));
}

std::string FuncSleep::toString() const {
    return "sleep";
}
