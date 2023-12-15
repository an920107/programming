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
unordered_map<string, Symbol> symbols;
%}

%code requires {
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include "include/python.hpp"
#include "include/symbol.hpp"
#include "include/util.hpp"
using namespace std;

#define _DEBUG_
}

%union {
    bool bool_val;
    int num_val;
    string* id_name;
    Symbol* symbol;
}

%token <id_name>ID
%token <bool_val>BOOL_VAL <num_val>NUM_VAL
%token ADD SUB
%token MUL DIV MOD
%token AND OR NOT
%token GT LT EQ
%token PRINT_B PRINT_N DEF FUN IF
%token LB RB

%type <symbol>exp <symbol>exps <symbol>variable <symbol>fun_call
      <symbol>if_exp <symbol>num_op <symbol>logical_op <symbol>fun_exp
      <symbol>add <symbol>substract <symbol>multiply <symbol>divide 
      <symbol>modulus <symbol>greater <symbol>less <symbol>equal
      <symbol>and_op <symbol>or_op <symbol>not_op
      <symbol>test_exp <symbol>then_exp <symbol>else_exp

%%

stmts: stmts stmt | stmt

stmt: exp |
def_stmt {
    string command($<symbol>1->name + "=" + $<symbol>1->command);
    if (is_debug) cout << ">" << command << "\n";
    py.commit(command);
} | 
print_stmt {
    string command("print(" + $<symbol>1->command + ")");
    if (is_debug) cout << ">" << command << "\n";
    py.commit(command);
}

print_stmt:
LB PRINT_B exp RB {
    if ($3->type != DataType::BOOLEAN) throw runtime_error("type mismatch.");
    $3->command = "'#t' if " + $3->command + " else '#f'";
    $<symbol>$ = $3;
} |
LB PRINT_N exp RB {
    if ($3->type != DataType::NUMBER) throw runtime_error("type mismatch.");
    $<symbol>$ = $3;
}

exp:
BOOL_VAL {
    $$ = new Symbol(DataType::BOOLEAN, $1 ? "True" : "False");
} |
NUM_VAL {
    $$ = new Symbol(DataType::NUMBER, to_string($1));
} | 
variable {
    if (symbols.find($1->name) == symbols.end())
        throw runtime_error("'" + $1->name + "' has not been defined.");
    $$ = $1;
} | num_op | logical_op | fun_exp | fun_call | if_exp

exps:
exps exp {
    if ($1->type != $2->type)
        throw runtime_error("type mismatch. the types of all the arguments must be same.");
    $$ = new Symbol($1->type, $1->command + "," + $2->command);
} | exp

num_op: add | substract | multiply | divide | modulus 
      | greater | less | equal

add: LB ADD exp exps RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '+' must be number.");
    auto params = split($4->command, ",");
    $$ = new Symbol(DataType::NUMBER, "(" + $3->command);
    for (auto param : params) $$->command += "+" + param;
    $$->command += ")";
}

substract: LB SUB exp exp RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '-' must be number.");
    $$ = new Symbol(
        DataType::NUMBER, "(" + $3->command + "-" + $4->command + ")");
}

multiply: LB MUL exp exps RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '*' must be number.");
    auto params = split($4->command, ",");
    $$ = new Symbol(DataType::NUMBER, "(" + $3->command);
    for (auto param : params) $$->command += "*" + param;
    $$->command += ")";
}

divide: LB DIV exp exp RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '/' must be number.");
    $$ = new Symbol(
        DataType::NUMBER, "(" + $3->command + "//" + $4->command + ")");
}

modulus: LB MOD exp exp RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after 'mod' must be number.");
    $$ = new Symbol(
        DataType::NUMBER, "(" + $3->command + "%" + $4->command + ")");
}

greater: LB GT exp exp RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '>' must be number.");
    $$ = new Symbol(
        DataType::BOOLEAN, "(" + $3->command + ">" + $4->command + ")");
}

less: LB LT exp exp RB {
    if ($3->type != DataType::NUMBER || $4->type != DataType::NUMBER)
        throw runtime_error("type mismatch. the types of arguments after '<' must be number.");
    $$ = new Symbol(
        DataType::BOOLEAN, "(" + $3->command + "<" + $4->command + ")");
}

equal: LB EQ exp exps RB {
    if (($3->type != DataType::NUMBER || $4->type != DataType::NUMBER) &&
        ($3->type != DataType::BOOLEAN || $4->type != DataType::BOOLEAN))
        throw runtime_error("type mismatch. the types of arguments after '=' must be same in boolean or number.");
    $$ = new Symbol(
        DataType::BOOLEAN, "(" + $3->command + "==" + $4->command + ")");
}

logical_op: and_op | or_op | not_op

and_op: LB AND exp exps RB {
    if ($3->type != DataType::BOOLEAN || $4->type != DataType::BOOLEAN)
        throw runtime_error("type mismatch. the types of arguments after 'and' must be boolean.");
    auto params = split($4->command, ",");
    $$ = new Symbol(DataType::BOOLEAN, "(" + $3->command);
    for (auto param : params) $$->command += " and " + param;
    $$->command += ")";
}

or_op: LB OR exp exps RB {
    if ($3->type != DataType::BOOLEAN || $4->type != DataType::BOOLEAN)
        throw runtime_error("type mismatch. the types of arguments after 'or' must be boolean.");
    auto params = split($4->command, ",");
    $$ = new Symbol(DataType::BOOLEAN, "(" + $3->command);
    for (auto param : params) $$->command += " or " + param;
    $$->command += ")";
}

not_op: LB NOT exp RB {
    if ($3->type != DataType::BOOLEAN)
        throw runtime_error("type mismatch. the type of argument after 'not' must be boolean.");
    $$ = new Symbol(DataType::BOOLEAN, "(not " + $3->command + ")");
}

def_stmt: LB DEF variable exp RB {
    Symbol new_symbol($3->name, $4->type, $4->command);
    symbols[$3->name] = new_symbol;
    $<symbol>$ = &new_symbol;
}

variable: ID {
    auto iter = symbols.find(*$1);
    if (iter != symbols.end()) $$ = &(iter->second);
    else $$ = new Symbol(*$1);
}

fun_exp: LB FUN LB fun_ids RB fun_body RB {}

fun_ids: fun_ids ID | ;

fun_body: exp

fun_call: LB fun_exp params RB {}
        | LB fun_name params RB {}

params: params exp | ;

fun_name: ID {};

if_exp: LB IF test_exp then_exp else_exp RB {
    if ($4->type != $5->type)
        throw runtime_error("type mismatch. the types of then_exp and else_exp must be same.");
    $$ = new Symbol(
        $5->type, "(" + $4->command + " if " + $3->command + " else " + $5->command + ")");
}

test_exp: exp {
    if ($1->type != DataType::BOOLEAN)
        throw runtime_error("type mismatch. test_exp should be boolean.");
    $$ = $1;
}

then_exp: exp {
    if ($1->type != DataType::BOOLEAN && $1->type != DataType::NUMBER)
        throw runtime_error("type mismatch. then_exp should be boolean or number.");
    $$ = $1;
}

else_exp: exp {
    if ($1->type != DataType::BOOLEAN && $1->type != DataType::NUMBER)
        throw runtime_error("type mismatch. else_exp should be boolean or number.");
    $$ = $1;
}

%%

void yyerror(const char* message) {
    throw runtime_error("syntax error.");
}

int main(int argc, char** argv) {
    try {
        yyparse();
        cout << py.exec() << "\n";
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }
    return 0;
}