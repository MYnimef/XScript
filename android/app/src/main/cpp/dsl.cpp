#include <jni.h>
#include <string>
#include <Lexer.h>
#include <Node.h>
#include <Interpreter.h>
#include <Parser.h>
#include <ExpBlock.h>
#include <sstream>
#include <FuncPrint.h>
#include <FuncPrintln.h>
#include <FuncToInteger.h>
#include <FuncToBool.h>
#include <FuncToDouble.h>
#include <FuncToString.h>
#include <FuncSleep.h>
#include <FuncToList.h>
#include <FuncSin.h>
#include <FuncCos.h>


extern "C"
JNIEXPORT void JNICALL
Java_com_mynimef_dsl_DSLViewModel_execute(JNIEnv* env, jobject obj, jstring code) {
    auto application = new Node(new ExpBlock(0, "main"));
    auto functions = new std::map<std::string, Node*> {
            { "bool1",     new Node( new FuncToBool       () ) },
            { "int1",      new Node( new FuncToInteger    () ) },
            { "float1",    new Node( new FuncToDouble     () ) },
            { "string1",   new Node( new FuncToString     () ) },
            { "list1",     new Node( new FuncToList       () ) },
            { "sleep1",    new Node( new FuncSleep        () ) },
            { "sin1",      new Node( new FuncSin          () ) },
            { "cos1",      new Node( new FuncCos          () ) },

            { "print1",    new Node( new FuncPrint     (env, obj) ) },
            { "println1",  new Node( new FuncPrintln   (env, obj) ) },
    };

    try {
        Lexer lexer;

        std::stringstream ss(env->GetStringUTFChars(code, nullptr));
        std::string line;
        for (int i = 0; std::getline(ss, line, '\n');) {
            lexer.scanLine(i, line);
        }

        Parser parser(application, functions);
        parser.addTokens(lexer.getTokens());

        Interpreter compiler(functions);
        compiler.execute(application);
    } catch (const std::exception& ex) {
        jstring jstr = env->NewStringUTF(ex.what());
        jclass clazz = env->FindClass("com/mynimef/dsl/DSLViewModel");
        jmethodID messageMe = env->GetMethodID(clazz, "addToOutput", "(Ljava/lang/String;)V");
        env->CallVoidMethod(obj, messageMe, jstr);
    }

    delete application;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;
}