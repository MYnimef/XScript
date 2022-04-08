//
// Created by Ivan Markov on 05.03.2022.
//

#include <fstream>
#include "Lexer.h"

Lexer::Lexer(): lexems({
    { ID,           std::regex( R"([a-zA-Z][a-zA-Z0-9_]*)" )      },
    { DOUBLE_DIGIT, std::regex( R"((0|([1-9][0-9]*))\.*[0-9]*)" ) }, // can be 0 but can't start with 0
    { INT_DIGIT,    std::regex( R"(0|([1-9][0-9]*))" )            }, // can be 0 but can't start with 0
    { STRING,       std::regex( R"("[^"]*")" )                    },
    { BOOL,         std::regex( R"((true)|(false))" )             },
    { FUNC_KW,      std::regex( R"(func)" )                       },
    { IF_KW,        std::regex( R"(if)" )                         },
    { ELSE_KW,      std::regex( R"(else)" )                       },
    { WHILE_KW,     std::regex( R"(while)" )                      },
    { FOR_KW,       std::regex( R"(for)" )                        },
    { L_BRACKET,    std::regex( R"(\()" )                         }, // can be only (
    { R_BRACKET,    std::regex( R"(\))" )                         }, // can be only )
    { L_BRACE,      std::regex( R"(\{)" )                         }, // can be only {
    { R_BRACE,      std::regex( R"(\})" )                         }, // can be only }
    { ASSIGN_OP,    std::regex( R"(=)" )                          },
    { INCREMENT_OP, std::regex( R"(\+\+)" )                       },
    { DECREMENT_OP, std::regex( R"(\-\-)" )                       },
    { SUM_OP,       std::regex( R"(\+)" )                         },
    { SUB_OP,       std::regex( R"(\-)" )                         },
    { MULT_OP,      std::regex( R"(\*)" )                         },
    { DIV_OP,       std::regex( R"(\/)" )                         },
    { COMMA,        std::regex( R"(,)")                           },
    { SEMICOLON,    std::regex( R"(;)" )                          },
}) {

}

Lexer::~Lexer() {

}

void Lexer::scanFile(const std::string& filename) {
    std::ifstream file("../src/" + filename);

    if (!file.is_open()) {
        throw std::invalid_argument( "can't open file " + filename );
    }

    std::string line;
    for (int i = 0; getline(file, line); i++) {
        if (!line.empty()) {
            std::string oldStr;

            for (int startIndex = 0, endIndex = 1; endIndex <= line.size(); endIndex++) {
                if (startIndex < endIndex) {
                    std::string newStr = line.substr(startIndex, endIndex - startIndex);

                    if (newStr == " ") {
                        startIndex++;
                        continue;
                    } else if (std::regex_match(newStr, std::regex(R"(("[^"]*)|(\|)|(&))"))) {
                        continue;
                    } else if (!checkToken(newStr)) {
                        addToken(oldStr.empty() ? newStr : oldStr, i);
                        endIndex--;
                        startIndex = endIndex;
                    } else if (endIndex == line.size()) {
                        addToken(newStr, i);
                        addToken(";", i);
                    }

                    oldStr = newStr;
                }
            }
        }
    }

    file.close();
}

bool Lexer::checkToken(const std::string& input) {
    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            return true;
        }
    }
    return false;
}

void Lexer::addToken(const std::string& input, const int& lineNum) {
    bool didFind = false;
    TokenType type;

    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            type = lexem.first;
            didFind = true;
        }
    }

    if (didFind) {
        tokens.emplace_back(type, input);
    } else {
        throw std::invalid_argument("wrong syntax at line " + std::to_string(lineNum + 1) + ": " + input);
    }
}

std::list<Token> Lexer::getTokens() {
    return tokens;
}
