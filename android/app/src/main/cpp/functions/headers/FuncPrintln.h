//
// Created by Ivan Markov on 05.08.2022.
//

#pragma once

#include <jni.h>
#include <ExpFuncCustom.h>

class FuncPrintln: public ExpFuncCustom {
private:
    JNIEnv* env;
    jobject obj;

public:
    FuncPrintln(JNIEnv* env, jobject obj);

    ~FuncPrintln() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    std::string toString() const override;
};
