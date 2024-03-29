//
// Created by Ivan Markov on 06.08.2022.
//

#include "FuncPrint.h"

FuncPrint::FuncPrint(JNIEnv* env, jobject obj):
        ExpFuncCustom({ "arg1" }),
        env(env),
        obj(obj) { }

void FuncPrint::action(
        const std::map<std::string, Var*>& params,
        std::stack<Var*>& stack
) const {
    const auto& arg1 = (std::string) *params.find("arg1")->second;

    jstring jstr = env->NewStringUTF(arg1.c_str());
    jclass clazz = env->FindClass("com/mynimef/dsl/DSLViewModel");
    jmethodID messageMe = env->GetMethodID(clazz, "addToOutput", "(Ljava/lang/String;)V");
    env->CallVoidMethod(obj, messageMe, jstr);
}

std::string FuncPrint::toString() const {
    return "println";
}

FuncPrint::~FuncPrint() = default;
