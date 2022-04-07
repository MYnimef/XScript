//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include <iostream>
#include <regex>
#include "Parser.h"
#include "ExpressionValInteger.h"
#include "ExpressionValDouble.h"
#include "ExpressionValString.h"
#include "ExpressionOpAssignment.h"
#include "ExpressionOpSum.h"
#include "ExpressionOpSub.h"
#include "ExpressionOpMult.h"
#include "ExpressionOpDiv.h"
#include "ExpressionVarInit.h"
#include "ExpressionVarCall.h"
#include "ExpressionFunctionCall.h"

Parser::Parser(const std::string& name):
grammatics({
    { GR_VAR_ASSIGNMENT_COMPLEX, std::regex( R"(id[\+\-\*\/]=(\-)?([\(]*((id\(.*\))|(id)|(i)|(d)|(s))[\)]*[\+\-\*\/])*[\(]*((id\(.*\))|(id)|(i)|(d)|(s))[\)]*)" ) },
    { GR_VAR_ASSIGNMENT,         std::regex( R"(id=(\-)?([\(]*((id\(.*\))|(id)|(i)|(d)|(s))[\)]*[\+\-\*\/])*[\(]*((id\(.*\))|(id)|(i)|(d)|(s))[\)]*)" )           },
    { GR_VAR_INCREMENT,          std::regex( R"(idI)" )                                                                                                           },
    { GR_VAR_DECREMENT,          std::regex( R"(idD)" )                                                                                                           },
    { GR_FUNC,                   std::regex( R"(id\(.*\))" )                                                                                                      },
    { GR_IF,                     std::regex( R"(if\(.*\)\{.*\}(elseif\(.*\)\{.*\})*(else\(.*\)\{.*\})?)" )                                                        },
    { GR_LOOP_WHILE,             std::regex( R"(while\(.*\)\{.*\})" )                                                                                             },
    { GR_LOOP_FOR,               std::regex( R"(for\(.*\)\{.*\})" )                                                                                               },
    { GR_FUNC_DEFINITION,        std::regex( R"(funcid\((((id,)*(id))|((id)?))\)\{.*\})" )                                                                        },
    { GR_CODE_BLOCK,             std::regex( R"(\{.*\})" )                                                                                                        }
}) {
    tree = new Node(new ExpressionFunctionCall("main"));
}

Parser::Parser(const std::map<GrammarType, std::regex>& grammatics):
grammatics(grammatics) {
    tree = new Node(new ExpressionFunctionCall("main"));
}

Parser::~Parser() {
    delete tree;
}

void Parser::addTokens(const std::list<Token>& tokens) {
    std::list<Token> tokensLine;

    int openedBrackets = 0;
    int openedBraces = 0;

    bool semicolon = false;
    bool op = false;

    for (const auto &token: tokens) {
        const auto &type = token.getType();

        if (type == SEMICOLON) {
            if (openedBraces == 0) {
                if (openedBrackets == 0) {
                    semicolon = true;
                }
            } else {
                tokensLine.push_back(token);
            }
        } else {
            if ((type == ID || token.isKeyWord()) && !op) {
                if (semicolon) {
                    if (!tokensLine.empty()) {
                        addTokensLine(tokensLine);
                        tokensLine.clear();
                    }
                }
            } else if (token.isOperator()) {
                op = true;
            } else if (type == L_BRACKET) {
                openedBrackets++;
            } else if (type == R_BRACKET) {
                openedBrackets--;
            } else if (type == L_BRACE) {
                openedBraces++;
            } else if (type == R_BRACE) {
                openedBraces--;
            } else {
                op = false;
            }

            semicolon = false;
            tokensLine.push_back(token);
        }
    }

    if (!tokensLine.empty()) {
        addTokensLine(tokensLine);
        tokensLine.clear();
    }
}

void Parser::addTokensLine(std::list<Token>& tokens) {
    std::cout << std::endl;
    for (const auto& i: tokens) {
        std::cout << i.getValue() << " ";
    }

    generateExpression(tokens);
}

void Parser::generateExpression(std::list<Token>& tokens) {
    GrammarType type = checkGrammar(tokens);

    switch (type) {
        case GR_VAR_ASSIGNMENT_COMPLEX:
            parseAssignmentComplex(tokens);
            break;
        case GR_VAR_ASSIGNMENT:
            parseAssignment(tokens);
            break;
        case GR_VAR_INCREMENT:
            parseIncrement(tokens);
            break;
        case GR_VAR_DECREMENT:
            parseDecrement(tokens);
            break;
        case GR_FUNC:
            break;
        case GR_IF:
            break;
        case GR_LOOP_WHILE:
            break;
        case GR_LOOP_FOR:
            break;
        case GR_FUNC_DEFINITION:
            parseFuncDefinition(tokens);
            break;
        case GR_CODE_BLOCK:
            break;
    }
}

Parser::GrammarType Parser::checkGrammar(std::list<Token>& tokens) {
    std::string comp;
    for (const auto &token: tokens) {
        comp += token.typeToString();
    }
    std::cout << comp;

    GrammarType type;
    bool didFind = false;

    for (const auto &grammar: grammatics) {
        if (std::regex_match(comp, grammar.second)) {
            type = grammar.first;
            didFind = true;
        }
    }

    if (didFind) {
        return type;
    } else {
        throw std::overflow_error("wrong grammar");
    }
}

void Parser::parseAssignmentComplex(std::list<Token>& tokens) {
    auto var = tokens.front();
    tokens.pop_front();
    auto op = tokens.front();
    tokens.pop_front();
    auto assign = tokens.front();
    tokens.pop_front();

    tokens.push_front(op);
    tokens.push_front(var);
    tokens.push_front(assign);
    tokens.push_front(var);

    parseAssignment(tokens);
}

void Parser::parseAssignment(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    expressions.emplace_back(new ExpressionVarInit(tokens.front().getValue()));
    tokens.pop_front();
    expressions.emplace_back(new ExpressionOpAssignment());
    tokens.pop_front();

    if (tokens.front().getType() == SUB_OP) {
        tokens.push_front(Token(INT_DIGIT, "0"));
    }

    expressions.splice(expressions.end(), parseOperations(tokens));

    tree->addChildBack(addNodeExpr(toPostfix(expressions)));
}

void Parser::parseIncrement(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    std::string id = tokens.front().getValue();
    tokens.clear();

    expressions.emplace_back(new ExpressionVarInit(id));
    expressions.emplace_back(new ExpressionVarCall(id));
    expressions.emplace_back(new ExpressionValInteger(1));
    expressions.emplace_back(new ExpressionOpSum());
    expressions.emplace_back(new ExpressionOpAssignment());

    tree->addChildBack(addNodeExpr(expressions));
}

void Parser::parseDecrement(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    std::string id = tokens.front().getValue();
    tokens.clear();

    expressions.emplace_back(new ExpressionVarInit(id));
    expressions.emplace_back(new ExpressionVarCall(id));
    expressions.emplace_back(new ExpressionValInteger(1));
    expressions.emplace_back(new ExpressionOpSub());
    expressions.emplace_back(new ExpressionOpAssignment());

    tree->addChildBack(addNodeExpr(expressions));
}

std::list<Expression*> Parser::parseOperations(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    std::stack<Token> stack;
    int brackets = 0;
    bool bracketsOver = false;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (token.isOperator() && brackets == 0) {
            subOperations(expressions, stack, bracketsOver);

            if (type == SUM_OP) {
                expressions.emplace_back(new ExpressionOpSum());
            } else if (type == SUB_OP) {
                expressions.emplace_back(new ExpressionOpSub());
            } else if (type == MULT_OP) {
                expressions.emplace_back(new ExpressionOpMult());
            } else {
                expressions.emplace_back(new ExpressionOpDiv());
            }
        } else if (type == L_BRACKET) {
            if (brackets != 0) {
                stack.push(token);
            } else {
                expressions.emplace_back(new ExpressionBracketL());
            }
            brackets++;
        } else if (type == R_BRACKET) {
            brackets--;
            if (brackets != 0) {
                stack.push(token);
            } else {
                bracketsOver = true;
            }
        } else {
            stack.push(token);
        }
    }

    subOperations(expressions, stack, bracketsOver);
    tokens.clear();
    return expressions;
}

void Parser::subOperations(std::list<Expression*>& expressions, std::stack<Token>& stack, bool bracketsOver) {
    std::list<Token> localTokens;
    while (!stack.empty()) {
        localTokens.push_front(stack.top());
        stack.pop();
    }

    std::string localString;
    for (const auto& localToken: localTokens) {
        localString += localToken.typeToString();
    }

    if (localString == "id") {
        expressions.emplace_back(new ExpressionVarCall(localTokens.front().getValue()));
    } else if (localString == "i") {
        expressions.emplace_back(new ExpressionValInteger(localTokens.front().getValue()));
    } else if (localString == "d") {
        expressions.emplace_back(new ExpressionValDouble(localTokens.front().getValue()));
    } else if (localString == "s") {
        expressions.emplace_back(new ExpressionValString(localTokens.front().getValue()));
    } else if (std::regex_match(localString, std::regex(R"(id\(.*\))"))) {

    } else if (!localTokens.empty()) {
        expressions.splice(expressions.end(), parseOperations(localTokens));

        if (bracketsOver) {
            expressions.emplace_back(new ExpressionBracketR());
        }
    }
}

//funcid\((((id,)*(id))|((id)+))\)\{.*\}
void Parser::parseFuncDefinition(std::list<Token>& tokens) {
    /*
    tokens.pop_front(); // remove func
    std::string funcName = tokens.front().getValue();
    tokens.pop_front(); // remove func name

    Node* node = new Node(expression(EXP_FUNC_DEFINITION, funcName));

    tokens.pop_front(); // remove (
    int amountOfArgs = 0;
    for (const auto& token: tokens) {
        if (token.getType() == R_BRACKET) {
            break;
        } else {
            node->addChildBack(new Node(expression(EXP_GET_FROM_LOCAL, token.getValue())));
            amountOfArgs++;
        }
    }
    funcName += std::to_string(amountOfArgs);

    for (int i = 0; i < amountOfArgs; i++) {
        tokens.pop_front();
    }

    tokens.pop_front(); // delete )
    tokens.pop_front(); // delete {
    tokens.pop_front(); // delete first ; (cuz generation)
    tokens.pop_back();  // delete }

    Parser parser(grammatics);
    parser.addTokens(tokens);
    node->addChildBack(parser.getTree());

    if (functions.count(funcName)) {
        throw std::overflow_error("attempt to re-declare function " + funcName);
    } else {
        functions.insert_or_assign(funcName, node);
    }
     */
}

std::list<Expression*> Parser::toPostfix(std::list<Expression*>& expressions) {
    std::list<Expression*> postfix;
    std::stack<Expression*> operators;

    for (auto* expression: expressions) {
        const auto& type = expression->getType();

        if (type == EXP_BRACKET_L) {
            operators.push(expression);
        } else if (type == EXP_BRACKET_R) {
            while (operators.top()->getType() != EXP_BRACKET_L) {
                postfix.push_back(operators.top());
                operators.pop();
            }

            auto prev = operators.top();
            operators.pop();
            delete prev;

            delete expression;
        } else if (expression->isOperator()) {
            while (!operators.empty() && operatorPriority(type) <= operatorPriority(operators.top()->getType())) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(expression);
        } else {
            postfix.push_back(expression);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

short Parser::operatorPriority(const ExpressionType& type) {
    if (type == EXP_OP_MULTIPLICATION || type == EXP_OP_DIVISION) {
        return 4;
    } else if (type == EXP_OP_SUM || type == EXP_OP_SUBTRACTION) {
        return 3;
    } else if (type == EXP_OP_ASSIGNMENT) {
        return 2;
    } else {
        return -1;
    }
}

Node* Parser::addNodeExpr(const std::list<Expression*>& postfix) {
    std::stack<Node*> st;

    for (const auto& exp: postfix) {
        Node* node = new Node(exp);
        if (node->getToken()->isOperator()) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        }
        st.push(node);
    }

    Node* result = st.top();
    st.pop();

    return result;
}

Node *Parser::getTree() {
    return tree;
}
