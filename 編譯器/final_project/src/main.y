%{
#include "main.tab.h"

extern int yylex(void);
extern void yyerror(const char*);

vector<ASTNode*> nodes;
Python py;
%}

%code requires {
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include "include/python.hpp"
#include "include/ast.hpp"
using namespace std;

#ifndef _YACC_DECLARE_
#define _YACC_DECLARE_
#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif
#endif

}

%union {
    int num_val;
    bool bool_val;
    string* text;
    ASTNode* node;
    vector<ASTNode*>* nodes;
}

%token <text>ID
%token <bool_val>BOOL_VAL <num_val>NUM_VAL
%token ADD SUB
%token MUL DIV MOD
%token AND OR NOT
%token GT LT EQ
%token PRINT_B PRINT_N DEF FUN IF
%token LB RB

%type <node> exp variable operation operator print_op fun_exp ldef_stmt fun_call
%type <nodes> exps_or_not params_or_not ldef_stmts_or_not

%%

stmts: stmts stmt {
    auto cmd = nodes.back()->traverse();
    if (is_debug)
        cout << "\n" << cmd << "\n";
    py.commit(cmd);
} | stmt {
    auto cmd = nodes.back()->traverse();
    if (is_debug)
        cout << "\n" << cmd << "\n";
    py.commit(cmd);
}

stmt: def_stmt | print_stmt | exp {
    nodes.push_back($1);
}

print_stmt: LB print_op exp RB {
    $2->append($3);
    nodes.push_back($2);
}

print_op: PRINT_B {
    $$ = new ASTNode(NodeType::OPERATOR, new char('b'));
} | PRINT_N {
    $$ = new ASTNode(NodeType::OPERATOR, new char('n'));
}

def_stmt: LB DEF ID exp RB {
    auto node = new ASTNode(NodeType::DEFINE, $3);
    node->append($4);
    nodes.push_back(node);
}

variable: ID {
    $$ = new ASTNode(NodeType::VARIABLE, $1);
}

exp: BOOL_VAL {
    $$ = new ASTNode(NodeType::BOOL_VAL, new bool($1));
} | NUM_VAL {
    $$ = new ASTNode(NodeType::NUMBER_VAL, new int($1));
} | variable | operation | fun_exp | fun_call

operation: LB operator exps_or_not RB {
    $$ = $2;
    for (auto node : *$3) $$->append(node);
}

exps_or_not: exps_or_not exp {
    $$->push_back($2);
} | {
    $$ = new vector<ASTNode*>();
} ;

operator: ADD {
    $$ = new ASTNode(NodeType::OPERATOR, new char('+'));
} | SUB {
    $$ = new ASTNode(NodeType::OPERATOR, new char('-'));
} | MUL {
    $$ = new ASTNode(NodeType::OPERATOR, new char('*'));
} | DIV {
    $$ = new ASTNode(NodeType::OPERATOR, new char('/'));
} | MOD {
    $$ = new ASTNode(NodeType::OPERATOR, new char('%'));
} | AND {
    $$ = new ASTNode(NodeType::OPERATOR, new char('&'));
} | OR {
    $$ = new ASTNode(NodeType::OPERATOR, new char('|'));
} | NOT {
    $$ = new ASTNode(NodeType::OPERATOR, new char('!'));
} | GT {
    $$ = new ASTNode(NodeType::OPERATOR, new char('>'));
} | LT {
    $$ = new ASTNode(NodeType::OPERATOR, new char('<'));
} | EQ {
    $$ = new ASTNode(NodeType::OPERATOR, new char('='));
} | IF {
    $$ = new ASTNode(NodeType::OPERATOR, new char('?'));
}

fun_exp: LB FUN LB params_or_not RB ldef_stmts_or_not exp RB {
    $$ = new ASTNode(NodeType::FUNCTION, $4);
    for (auto node : *$6) $$->append(node);
    $$->append($7);
}

params_or_not: params_or_not variable {
    $$->push_back($2);
} | {
    $$ = new vector<ASTNode*>();
} ;

fun_call: LB variable exps_or_not RB {
    $$ = new ASTNode(NodeType::CALL, $2);
    for (auto node : *$3) $$->append(node);
} | LB fun_exp exps_or_not RB {
    $$ = new ASTNode(NodeType::CALL, $2);
    for (auto node : *$3) $$->append(node);
}

ldef_stmts_or_not: ldef_stmts_or_not ldef_stmt {
    $$->push_back($2);
} | {
    $$ = new vector<ASTNode*>();
} ;

ldef_stmt: LB DEF ID exp RB {
    $$ = new ASTNode(NodeType::DEFINE, $3);
    $$->append($4);
}

%%

void yyerror(const char* message) {
    throw runtime_error("Syntax error.");
}

int main(int argc, char** argv) {
    try {
        if (argc > 1) py.filename = string(argv[1]);
        py.commit("from type import *\n");
        yyparse();
        cout << py.exec();
    } catch (const exception& e) {
        if (is_debug) cout << "\n";
        cout << e.what() << "\n";
        return 1;
    }
    return 0;
}