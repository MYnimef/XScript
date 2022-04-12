//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include <iostream>
#include <regex>
#include "Parser.h"
#include "ExpValBool.h"
#include "ExpValInteger.h"
#include "ExpValDouble.h"
#include "ExpValString.h"
#include "ExpOpSum.h"
#include "ExpOpSub.h"
#include "ExpOpMult.h"
#include "ExpOpDiv.h"
#include "ExpOpAssignVar.h"
#include "ExpVarCall.h"
#include "ExpBlockIf.h"
#include "ExpLogicalAnd.h"
#include "ExpLogicalOr.h"
#include "ExpLogicalEqual.h"
#include "ExpLogicalGreaterOrEqual.h"
#include "ExpLogicalSmallerOrEqual.h"
#include "ExpLogicalGreater.h"
#include "ExpLogicalSmaller.h"
#include "ExpLogicalNotEqual.h"
#include "ExcParser.h"
#include "ExpLogicalNot.h"
#include "ExpBlockWhile.h"
#include "ExpFuncCall.h"
#include "ExpBlock.h"
#include "ExpFuncDef.h"
#include "ExpOpAssignVarFunc.h"

Parser::Parser(Node* node, std::map<std::string, Node*>* functions):
tree(node),
functions(functions),
val(R"(([!\-]?\()*[!\-]?((@\(.*\))|[@bids])\)*(([\+\-\*\/<>GSEN\|&])*(!?\(\-?)*!?((@\(.*\))|[@bids])\)*)*)"),
syntax({
    { GR_FUNC,                    std::regex( R"(@\((()" + val + R"(,)*)" + val + R"()?)" + R"(\))" ) },
    { GR_VAR_ASSIGNMENT_COMPLEX,  std::regex( R"(@[\+\-\*\/]=)" + val )                               },
    { GR_VAR_ASSIGNMENT,          std::regex( R"(@=)" + val )                                         },
    { GR_VAR_INCREMENT_DECREMENT, std::regex( R"(@[ID])" )                                            },
    { GR_IF,                      std::regex( R"(if)" + val + R"(\{.*\})" )                           },
    { GR_LOOP_WHILE,              std::regex( R"(while)" + val + R"(\{.*\})" )                        },
    { GR_LOOP_FOR,                std::regex( R"(for\(.*\)\{.*\})" )                                  },
    { GR_FUNC_DEFINITION,         std::regex( R"(func@\(((@,)*@)?\)\{.*\})" )                         }
}) {
    tree = node;
}

Parser::Parser(Node* node, std::map<std::string, Node*>* functions, const std::string& actions, const std::map<GrammarType, std::regex>& grammatics):
        tree(node),
        functions(functions),
        val(actions),
        syntax(grammatics) {
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

    for (const auto &grammar: syntax) {
        if (std::regex_match(comp, grammar.second)) {
            return grammar.first;
        }
    }

    throw ExcParser("wrong syntax");
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
    std::list<Exp*> expressions;

    expressions.emplace_back(new ExpOpAssignVar(tokens.front().getValue()));
    tokens.pop_front(); // delete id
    tokens.pop_front(); // delete =
    expressions.splice(expressions.end(), parseOperations(tokens));

    tree->addChildBack(addNodeExpr(toPostfix(expressions)));
}

void Parser::parseIncrementDecrement(std::list<Token>& tokens) {
    std::list<Exp*> expressions;

    std::string id = tokens.front().getValue();
    tokens.pop_front();
    auto op = tokens.front().getType();
    tokens.clear();

    expressions.emplace_back(new ExpVarCall(id));
    expressions.emplace_back(new ExpValInteger(1));
    if (op == INCREMENT_OP) {
        expressions.emplace_back(new ExpOpSum());
    } else {
        expressions.emplace_back(new ExpOpSub());
    }
    expressions.emplace_back(new ExpOpAssignVar(id));

    tree->addChildBack(addNodeExpr(expressions));
}

std::list<Exp*> Parser::parseOperations(std::list<Token>& tokens) {
    std::list<Exp*> expressions;

    std::list<Token> localTokens;
    int brackets = 0;
    bool foundId = false;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (token.isOperator() && brackets == 0) {
            if (localTokens.size() == 0 && type == SUB_OP) {
                expressions.emplace_back(new ExpValInteger(0));
                expressions.emplace_back(new ExpOpSub());
            } else {
                subOperations(expressions, localTokens);

                if (type == SUM_OP) {
                    expressions.emplace_back(new ExpOpSum());
                } else if (type == SUB_OP) {
                    expressions.emplace_back(new ExpOpSub());
                } else if (type == MULT_OP) {
                    expressions.emplace_back(new ExpOpMult());
                } else if (type == DIV_OP) {
                    expressions.emplace_back(new ExpOpDiv());
                } else if (type == AND_OP) {
                    expressions.emplace_back(new ExpLogicalAnd());
                } else if (type == OR_OP) {
                    expressions.emplace_back(new ExpLogicalOr());
                } else if (type == EQUAL_OP) {
                    expressions.emplace_back(new ExpLogicalEqual());
                } else if (type == GREATER_OR_EQUAL_OP) {
                    expressions.emplace_back(new ExpLogicalGreaterOrEqual());
                } else if (type == SMALLER_OR_EQUAL_OP) {
                    expressions.emplace_back(new ExpLogicalSmallerOrEqual());
                } else if (type == GREATER_OP) {
                    expressions.emplace_back(new ExpLogicalGreater());
                } else if (type == SMALLER_OP) {
                    expressions.emplace_back(new ExpLogicalSmaller());
                } else if (type == NOT_EQUAL_OP) {
                    expressions.emplace_back(new ExpLogicalNotEqual());
                } else {
                    expressions.emplace_back(new ExpLogicalNot());
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
        throw ExcParser("expected )");
    } else if (brackets < 0) {
        throw ExcParser("expected (");
    } else {
        subOperations(expressions, localTokens);
        tokens.clear();
        return expressions;
    }
}

void Parser::subOperations(std::list<Exp*>& expressions, std::list<Token>& localTokens) {
    std::string localString;
    for (const auto& localToken: localTokens) {
        localString += localToken.typeToString();
    }

    if (localString == "@") {
        expressions.emplace_back(new ExpVarCall(localTokens.front().getValue()));
    } else if (localString == "b") {
        expressions.emplace_back(new ExpValBool(localTokens.front().getValue()));
    } else if (localString == "i") {
        expressions.emplace_back(new ExpValInteger(localTokens.front().getValue()));
    } else if (localString == "d") {
        expressions.emplace_back(new ExpValDouble(localTokens.front().getValue()));
    } else if (localString == "s") {
        expressions.emplace_back(new ExpValString(localTokens.front().getValue()));
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
            arguments.push_back(new Node(new ExpOpAssignVarFunc(token.getValue())));
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
        for (auto arg: arguments) {
            delete arg;
        }
        throw ExcParser("attempt to re-declare function " + id);
    } else {
        auto funcBody = new Node(new ExpBlock(funcName));
        auto functionsLocal = new std::map<std::string, Node*>();
        Parser parser(funcBody, functionsLocal, val, syntax);
        parser.addTokens(tokens);

        auto node = new Node(new ExpFuncDef(funcName, funcBody, functionsLocal), arguments);
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

    Node* blockExecute = new Node(new ExpBlock("if"));
    auto functionsLocal = new std::map<std::string, Node*>();
    Parser parser(blockExecute, functionsLocal, val, syntax);
    parser.addTokens(tokens);

    tree->addChildBack(new Node(new ExpBlockIf(conditionBlock, blockExecute, functionsLocal)));
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

    Node* blockExecute = new Node(new ExpBlock("while"));

    auto functionsLocal = new std::map<std::string, Node*>();
    Parser parser(blockExecute, functionsLocal, val, syntax);
    parser.addTokens(tokens);

    tree->addChildBack(new Node(new ExpBlockWhile(conditionBlock, blockExecute, functionsLocal)));
}

void Parser::parseFunctionCall(std::list<Token>& tokens) {
    tree->addChildBack(new Node(subFunction(tokens)));
}

Exp* Parser::subFunction(std::list<Token>& tokens) {
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
        arguments.push_front(addNodeExpr(toPostfix(exp)));
        amountOfArgs++;
    }

    id += std::to_string(amountOfArgs);
    return new ExpFuncCall(id, arguments);
}

std::list<Exp*> Parser::toPostfix(std::list<Exp*>& expressions) {
    std::list<Exp*> postfix;
    std::stack<Exp*> operators;

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

Node* Parser::addNodeExpr(const std::list<Exp*>& postfix) {
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
