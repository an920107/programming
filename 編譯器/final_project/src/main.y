%{
#include "main.tab.h"

#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif

extern int yylex(void);
extern void yyerror(const char*);

Python py;
stack<void*> esp;

// 沒有全域區域之分，進入點為預設的 main_func，
// 宣告變數時往 parent 尋找最近 Function
Function main_func;
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
#include "include/object.hpp"
using namespace std;

#define _DEBUG_
}

%union {
    int num_val;
    bool bool_val;
    string* text;
    Number* num_obj;
    Boolean* bool_obj;
}

%token <text>ID
%token BOOL_VAL NUM_VAL
%token ADD SUB
%token MUL DIV MOD
%token AND OR NOT
%token GT LT EQ
%token PRINT_B PRINT_N DEF FUN IF
%token LB RB

%%

stmts: stmts stmt | stmt

stmt: def_stmt | print_stmt | exp

print_stmt: LB print_op exp RB

print_op: PRINT_B | PRINT_N

def_stmt: LB DEF variable exp RB

variable: ID

exp: BOOL_VAL | NUM_VAL | variable | operation | fun_exp | fun_call

operation: LB operator args_or_not RB

operator: ADD | SUB | MUL | DIV | MOD | AND | OR | NOT | GT | LT | EQ | IF

fun_exp: LB FUN LB params_or_not RB def_stmts_or_not exp RB

params_or_not: params_or_not ID | ;

fun_call: LB variable args_or_not RB | LB fun_exp args_or_not RB

args_or_not: args_or_not exp | ;

def_stmts_or_not: def_stmts_or_not def_stmt | ;

%%

void yyerror(const char* message) {
    throw runtime_error("syntax error.");
}

int main(int argc, char** argv) {
    try {
        yyparse();
    } catch (const exception& e) {
        cout << e.what() << "\n";
        return 1;
    }
    return 0;
}