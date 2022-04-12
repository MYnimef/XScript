//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include <iostream>
#include <regex>
#include "Parser.h"
#include "ExpressionValBool.h"
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
#include "ExpressionIf.h"
#include "ExpressionOpLogicalAnd.h"
#include "ExpressionOpLogicalOr.h"
#include "ExpressionOpEqual.h"
#include "ExpressionOpGreaterOrEqual.h"
#include "ExpressionOpSmallerOrEqual.h"
#include "ExpressionOpGreater.h"
#include "ExpressionOpSmaller.h"
#include "ExpressionOpNotEqual.h"
#include "ExceptionParser.h"
#include "ExpressionOpNot.h"
#include "ExpressionWhile.h"
#include "ExpressionFunctionCall.h"
#include "ExpressionCodeBlock.h"
#include "ExpressionFunctionDef.h"

Parser::Parser(Node* node, std::map<std::string, Node*>* functions):
tree(node),
functions(functions),
actions(R"(([!\-]?\()*[!\-]?((@\(.*\))|[@bids])\)*(([\+\-\*\/<>GSEN\|&])*(!?\(\-?)*!?((@\(.*\))|[@bids])\)*)*)"),
grammatics({
    { GR_FUNC,                    std::regex( R"(@\((()" + actions + R"(,)*)" + actions + R"()?)" + R"(\))" ) },
    { GR_VAR_ASSIGNMENT_COMPLEX,  std::regex( R"(@[\+\-\*\/]=)" + actions )                                   },
    { GR_VAR_ASSIGNMENT,          std::regex( R"(@=)" + actions )                                             },
    { GR_VAR_INCREMENT_DECREMENT, std::regex( R"(@[ID])" )                                                    },
    { GR_IF,                      std::regex( R"(if)" + actions + R"(\{.*\})" )                               },
    { GR_LOOP_WHILE,              std::regex( R"(while)" + actions + R"(\{.*\})" )                            },
    { GR_LOOP_FOR,                std::regex( R"(for\(.*\)\{.*\})" )                                          },
    { GR_FUNC_DEFINITION,         std::regex( R"(func@\(((@,)*@)?\)\{.*\})" )                                 }
}) {
    tree = node;
}

Parser::Parser(Node* node, std::map<std::string, Node*>* functions, const std::string& actions, const std::map<GrammarType, std::regex>& grammatics):
tree(node),
functions(functions),
actions(actions),
grammatics(grammatics) {
}

Parser::~Parser() {

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
        case GR_VAR_INCREMENT_DECREMENT:
            parseIncrementDecrement(tokens);
            break;
        case GR_FUNC:
            parseFunctionCall(tokens);
            break;
        case GR_IF:
            parseIf(tokens);
            break;
        case GR_LOOP_WHILE:
            parseWhile(tokens);
            break;
        case GR_LOOP_FOR:
            break;
        case GR_FUNC_DEFINITION:
            parseFuncDefinition(tokens);
            break;
    }
}

Parser::GrammarType Parser::checkGrammar(std::list<Token>& tokens) {
    std::string comp;
    for (const auto &token: tokens) {
        comp += token.typeToString();
    }
    std::cout << comp;

    for (const auto &grammar: grammatics) {
        if (std::regex_match(comp, grammar.second)) {
            return grammar.first;
        }
    }

    throw ExceptionParser("wrong grammar");
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
    expressions.splice(expressions.end(), parseOperations(tokens));

    tree->addChildBack(addNodeExpr(toPostfix(expressions)));
}

void Parser::parseIncrementDecrement(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    std::string id = tokens.front().getValue();
    tokens.pop_front();
    auto op = tokens.front().getType();
    tokens.clear();

    expressions.emplace_back(new ExpressionVarInit(id));
    expressions.emplace_back(new ExpressionVarCall(id));
    expressions.emplace_back(new ExpressionValInteger(1));
    if (op == INCREMENT_OP) {
        expressions.emplace_back(new ExpressionOpSum());
    } else {
        expressions.emplace_back(new ExpressionOpSub());
    }
    expressions.emplace_back(new ExpressionOpAssignment());

    tree->addChildBack(addNodeExpr(expressions));
}

std::list<Expression*> Parser::parseOperations(std::list<Token>& tokens) {
    std::list<Expression*> expressions;

    std::list<Token> localTokens;
    int brackets = 0;
    bool foundId = false;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (token.isOperator() && brackets == 0) {
            if (localTokens.size() == 0 && type == SUB_OP) {
                expressions.emplace_back(new ExpressionValInteger(0));
                expressions.emplace_back(new ExpressionOpSub());
            } else {
                subOperations(expressions, localTokens);

                if (type == SUM_OP) {
                    expressions.emplace_back(new ExpressionOpSum());
                } else if (type == SUB_OP) {
                    expressions.emplace_back(new ExpressionOpSub());
                } else if (type == MULT_OP) {
                    expressions.emplace_back(new ExpressionOpMult());
                } else if (type == DIV_OP) {
                    expressions.emplace_back(new ExpressionOpDiv());
                } else if (type == AND_OP) {
                    expressions.emplace_back(new ExpressionOpLogicalAnd());
                } else if (type == OR_OP) {
                    expressions.emplace_back(new ExpressionOpLogicalOr());
                } else if (type == EQUAL_OP) {
                    expressions.emplace_back(new ExpressionOpEqual());
                } else if (type == GREATER_OR_EQUAL_OP) {
                    expressions.emplace_back(new ExpressionOpGreaterOrEqual());
                } else if (type == SMALLER_OR_EQUAL_OP) {
                    expressions.emplace_back(new ExpressionOpSmallerOrEqual());
                } else if (type == GREATER_OP) {
                    expressions.emplace_back(new ExpressionOpGreater());
                } else if (type == SMALLER_OP) {
                    expressions.emplace_back(new ExpressionOpSmaller());
                } else if (type == NOT_EQUAL_OP) {
                    expressions.emplace_back(new ExpressionOpNotEqual());
                } else {
                    expressions.emplace_back(new ExpressionOpNot());
                }
            }

            foundId = false;
        } else if (type == L_BRACKET) {
            if (brackets != 0 || foundId) {
                localTokens.push_back(token);
            } else {
                expressions.emplace_back(new ExpressionBracketL());
            }
            brackets++;
        } else if (type == R_BRACKET) {
            brackets--;
            if (brackets != 0 || foundId) {
                localTokens.push_back(token);
                foundId = false;
            } else {
                subOperations(expressions, localTokens);
                expressions.emplace_back(new ExpressionBracketR());
            }
        } else {
            if (type == ID && brackets == 0) {
                foundId = true;
            } else {
                foundId = false;
            }
            localTokens.push_back(token);
        }
    }

    if (brackets > 0) {
        throw ExceptionParser("expected )");
    } else if (brackets < 0) {
        throw ExceptionParser("expected (");
    } else {
        subOperations(expressions, localTokens);
        tokens.clear();
        return expressions;
    }
}

void Parser::subOperations(std::list<Expression*>& expressions, std::list<Token>& localTokens) {
    std::string localString;
    for (const auto& localToken: localTokens) {
        localString += localToken.typeToString();
    }

    if (localString == "@") {
        expressions.emplace_back(new ExpressionVarCall(localTokens.front().getValue()));
    } else if (localString == "b") {
        expressions.emplace_back(new ExpressionValBool(localTokens.front().getValue()));
    } else if (localString == "i") {
        expressions.emplace_back(new ExpressionValInteger(localTokens.front().getValue()));
    } else if (localString == "d") {
        expressions.emplace_back(new ExpressionValDouble(localTokens.front().getValue()));
    } else if (localString == "s") {
        expressions.emplace_back(new ExpressionValString(localTokens.front().getValue()));
    } else if (std::regex_match(localString, std::regex(R"(@\(.*\))"))) {
        expressions.emplace_back(subFunction(localTokens));
    } else if (!localTokens.empty()) {
        expressions.splice(expressions.end(), parseOperations(localTokens));
    }

    localTokens.clear();
}

void Parser::parseFuncDefinition(std::list<Token>& tokens) {
    tokens.pop_front(); // remove func
    std::string id = tokens.front().getValue();
    tokens.pop_front(); // remove func name

    tokens.pop_front(); // remove (
    int amountOfArgs = 0;

    std::list<Node*> arguments;
    for (const auto& token: tokens) {
        auto type = token.getType();

        if (type == R_BRACKET) {
            break;
        } else if (type != COMMA) {
            Node* node = new Node(new ExpressionOpAssignment());
            node->addChildBack(new Node(new ExpressionVarInit(token.getValue())));
            arguments.push_back(node);
            amountOfArgs++;
        }
    }

    auto funcName = id + std::to_string(amountOfArgs);

    {
        int remove = amountOfArgs;
        if (remove > 1) {
            remove += remove - 1;
        }
        for (int i = 0; i < remove; i++) {
            tokens.pop_front();
        }
    }

    tokens.pop_front(); // delete )
    tokens.pop_front(); // delete {
    tokens.pop_back();  // delete }

    if (functions->count(funcName)) {
        throw ExceptionParser("attempt to re-declare function " + id);
    } else {
        auto funcBody = new Node(new ExpressionCodeBlock(funcName));
        auto functionsLocal = new std::map<std::string, Node*>();
        Parser parser(funcBody, functionsLocal, actions, grammatics);
        parser.addTokens(tokens);

        auto node = new Node(new ExpressionFunctionDef(funcName, funcBody, functionsLocal));
        for (auto arg: arguments) {
            node->addChildBack(arg);
        }
        functions->insert_or_assign(funcName, node);
    }
}

void Parser::parseIf(std::list<Token>& tokens) {
    tokens.pop_front(); // remove if

    std::list<Token> localTokens;
    int amount = 0;
    for (const auto& token: tokens) {
        if (token.getType() != L_BRACE) {
            localTokens.push_back(token);
            amount++;
        } else {
            break;
        }
    }

    for (int i = 0; i < amount; i++) {
        tokens.pop_front();
    }

    auto condition = parseOperations(localTokens);
    auto conditionBlock = addNodeExpr(toPostfix(condition));

    tokens.pop_front(); // remove {
    tokens.pop_back();  // remove }

    Node* blockExecute = new Node(new ExpressionCodeBlock("if"));
    auto functionsLocal = new std::map<std::string, Node*>();
    Parser parser(blockExecute, functionsLocal, actions, grammatics);
    parser.addTokens(tokens);

    tree->addChildBack(new Node(new ExpressionIf(conditionBlock, blockExecute, functionsLocal)));
}

void Parser::parseWhile(std::list<Token>& tokens) {
    tokens.pop_front(); // remove while

    std::list<Token> localTokens;
    int amount = 0;
    for (const auto& token: tokens) {
        if (token.getType() != L_BRACE) {
            localTokens.push_back(token);
            amount++;
        } else {
            break;
        }
    }

    for (int i = 0; i < amount; i++) {
        tokens.pop_front();
    }

    auto condition = parseOperations(localTokens);
    auto conditionBlock = addNodeExpr(toPostfix(condition));

    tokens.pop_front(); // remove {
    tokens.pop_back();  // remove }

    Node* blockExecute = new Node(new ExpressionCodeBlock("while"));

    auto functionsLocal = new std::map<std::string, Node*>();
    Parser parser(blockExecute, functionsLocal, actions, grammatics);
    parser.addTokens(tokens);

    tree->addChildBack(new Node(new ExpressionWhile(conditionBlock, blockExecute, functionsLocal)));
}

void Parser::parseFunctionCall(std::list<Token>& tokens) {
    tree->addChildBack(new Node(subFunction(tokens)));
}

Expression* Parser::subFunction(std::list<Token>& tokens) {
    auto id = tokens.front().getValue();
    tokens.pop_front(); // remove id

    tokens.pop_front(); // remove (
    tokens.pop_back(); // remove )

    std::list<Node*> arguments;
    std::list<Token> localTokens;
    int amountOfArgs = 0;
    int brackets = 0;

    for (const auto& token: tokens) {
        auto type = token.getType();

        if (type == COMMA && brackets == 0) {
            auto exp = parseOperations(localTokens);
            arguments.push_front(addNodeExpr(toPostfix(exp)));
            amountOfArgs++;
        } else {
            if (type == L_BRACKET) {
                brackets++;
            } else if (type == R_BRACKET) {
                brackets--;
            }
            localTokens.push_back(token);
        }
    }

    if (!localTokens.empty()) {
        auto exp = parseOperations(localTokens);
        arguments.push_back(addNodeExpr(toPostfix(exp)));
        amountOfArgs++;
    }

    id += std::to_string(amountOfArgs);
    return new ExpressionFunctionCall(id, arguments);
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
        } else if (expression->isOperation()) {
            while (!operators.empty() && operatorPriority(type) >= operatorPriority(operators.top()->getType())) {
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

    std::cout<<std::endl;
    for (auto i: postfix) {
        std::cout << i->toString();
    }
    std::cout<<std::endl;

    return postfix;
}

short Parser::operatorPriority(const ExpressionType& type) {
    if (type == EXP_OP_NOT) {
        return 0;
    } else if (type == EXP_OP_MULTIPLICATION || type == EXP_OP_DIVISION) {
        return 1;
    } else if (type == EXP_OP_SUM || type == EXP_OP_SUBTRACTION) {
        return 2;
    } else if (type == EXP_OP_SMALLER || type == EXP_OP_SMALLER_OR_EQUAL || type == EXP_OP_GREATER || type == EXP_OP_GREATER_OR_EQUAL) {
        return 3;
    } else if (type == EXP_OP_EQUAL || type == EXP_OP_NOT_EQUAL) {
        return 4;
    } else if (type == EXP_LOGICAL_AND) {
        return 5;
    } else if (type == EXP_LOGICAL_OR) {
        return 6;
    } else { //type == EXP_OP_ASSIGNMENT
        return 7;
    }
}

Node* Parser::addNodeExpr(const std::list<Expression*>& postfix) {
    std::stack<Node*> st;

    for (const auto& exp: postfix) {
        Node* node = new Node(exp);
        if (node->getExpression()->isBinaryOperation()) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        } else if (node->getExpression()->isUnaryOperation()) {
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
