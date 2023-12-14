%{
#include "main.tab.h"

extern int yylex(void);
extern void yyerror(const char*);
%}

%code requires {
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "include/python.hpp"
#include "include/variable.hpp"
using namespace std;
}

%union {
    bool bool_val;
    int num_val;
    Variable* var;
}

%token <var>ID
%token <bool_val>BOOL_VAL <num_val>NUM_VAL
%token ADD SUB
%token MUL DIV MOD
%token AND OR NOT
%token GT LT EQ
%token PRINT_B PRINT_N DEF FUN IF
%token LB RB SEP

%%

stmts: stmts stmt | stmt;

stmt: exp | def_stmt | print_stmt;

print_stmt: LB PRINT_B SEP exp RB {}
          | LB PRINT_N SEP exp RB {};

exp: BOOL_VAL | NUM_VAL | variable | num_op | logical_op
   | fun_exp | fun_call | if_exp;

exps: exps exp | exp;

num_op: add | substract | multiply | divide | modulus 
      | greater | less | equal;

add: LB ADD SEP exp SEP exps RB {};

substract: LB SUB SEP exp SEP exp RB {};

multiply: LB MUL SEP exp SEP exps RB {};

divide: LB DIV SEP exp SEP exp RB {};

modulus: LB MOD SEP exp SEP exp RB {};

greater: LB GT SEP exp SEP exp RB {};

less: LB LT SEP exp SEP exp RB {};

equal: LB EQ SEP exp SEP exps RB {};

logical_op: and_op | or_op | not_op;

and_op: LB AND SEP exp SEP exps RB {};

or_op: LB OR SEP exp SEP exps RB {};

not_op: LB NOT SEP exp RB {};

def_stmt: LB DEF SEP variable SEP exp RB {};

variable: ID {};

fun_exp: LB FUN SEP fun_ids SEP fun_body RB {};

fun_ids: fun_ids SEP ID | ;

fun_body: exp;

fun_call: LB fun_exp SEP params RB {}
        | LB fun_name SEP params RB {};

params: params SEP exp | ;

fun_name: ID {};

if_exp: LB IF SEP test_exp SEP then_exp SEP else_exp RB {};

test_exp: exp;

then_exp: exp;

else_exp: exp;

%%

void yyerror(const char* message) {
    printf("%s\n", message);
}

int main(int argc, char** argv) {
    try {
        yyparse();
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }
    return 0;
}