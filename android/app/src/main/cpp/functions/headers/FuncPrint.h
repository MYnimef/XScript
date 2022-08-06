//
// Created by Ivan Markov on 06.08.2022.
//

#pragma once

#include <jni.h>
#include <ExpFuncCustom.h>

class FuncPrint: public ExpFuncCustom {
private:
    JNIEnv* env;
    jobject obj;

public:
    FuncPrint(JNIEnv* env, jobject obj);

    ~FuncPrint() override;

    void action(const std::map<std::string, Var*>& params, std::stack<Var*>& stack) const override;

    std::string toString() const override;
};
