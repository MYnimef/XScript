#include <iostream>
#include <fstream>
#include <FuncToBool.h>
#include <FuncToInteger.h>
#include <FuncToDouble.h>
#include <FuncToString.h>
#include <FuncToList.h>
#include <FuncSleep.h>
#include <FuncSin.h>
#include <FuncCos.h>

#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "ExcParser.h"
#include "ExpBlock.h"
#include "FuncPrint.h"
#include "FuncPrintln.h"
#include "FuncInput.h"
#include "FuncList.h"
#include "FuncClearConsole.h"


int main() {
    std::cout <<
    std::endl <<
    "\033[1;32m" <<
    " ____  ____  _       _             __  ____   __     _                 __ \n"
    "|  _ \\/ ___|| |     | |__  _   _  |  \\/  \\ \\ / / __ (_)_ __ ___   ___ / _|\n"
    "| | | \\___ \\| |     | '_ \\| | | | | |\\/| |\\ V / '_ \\| | '_ ` _ \\ / _ \\ |_ \n"
    "| |_| |___) | |___  | |_) | |_| | | |  | | | || | | | | | | | | |  __/  _|\n"
    "|____/|____/|_____| |_.__/ \\__, | |_|  |_| |_||_| |_|_|_| |_| |_|\\___|_|  \n"
    "                           |___/                                          \n"
    "\033[0m" <<
    std::endl;

    auto start = clock();

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

            { "print1",    new Node( new FuncPrint        () ) },
            { "println1",  new Node( new FuncPrintln      () ) },
            { "input0",    new Node( new FuncInput        () ) },
            { "list0",     new Node( new FuncList         () ) },
            { "clc0",      new Node( new FuncClearConsole () ) },
    };

    try {
        std::ifstream file("../main.dsl");

        if (!file.is_open()) {
            file.close();
            throw "end";
        }

        Lexer lexer;

        std::string line;
        for (int i = 0; getline(file, line); i++) {
            if (!line.empty()) {
                lexer.scanLine(i, line);
            }
        }

        file.close();

        Parser parser(application, functions);
        parser.addTokens(lexer.getTokens());

        Interpreter compiler(functions);
        compiler.execute(application);
    } catch (const std::exception& ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m";
    }

    delete application;
    for (const auto& func: *functions) {
        delete func.second;
    }
    delete functions;

    std::cout <<
    std::endl <<
    "\033[1;32m" <<
    "Program compiled in " <<
    (double) (clock() - start) / CLOCKS_PER_SEC <<
    " seconds"  << "\033[0m" <<
    std::endl;

    return 0;
}
