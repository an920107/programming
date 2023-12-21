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
State scope(&main_func);
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
#include "include/object.hpp"
#include "include/operator.hpp"
#include "include/state.hpp"
#include "include/execute.hpp"
using namespace std;

#define _DEBUG_
}

%union {
    string* text;
    ASTNode* node;
    Object* obj;
    Function* fun_obj;
    Number* num_obj;
    Boolean* bool_obj;
    Operator* opr;
}

%token <text>ID
%token <bool_obj>BOOL_VAL <num_obj>NUM_VAL
%token ADD SUB
%token MUL DIV MOD
%token AND OR NOT
%token GT LT EQ
%token PRINT_B PRINT_N DEF FUN IF
%token LB RB

%type <node>exp exps params fun_body
%type <obj>variable
%type <opr>opr_exp add substract multiply divide modulus
      greater less equal and_op or_op not_op if_exp
%type <fun_obj>fun_exp fun_call fun_name fun_var

%%

stmts: stmts stmt | stmt

stmt: def_stmt {
    scope.reset();
} | exec {
    if (is_debug)
        scope.back()->traverse();
    execute(scope);
    scope.reset();
}

exec: exp | print_stmt

print_stmt:
LB PRINT_B {
    scope.append(new Operator(DataType::NONE, "pb"));
} exp RB {
    ((Operator*)scope.back())->append($4);
    scope.pop_back();
} |
LB PRINT_N {
    scope.append(new Operator(DataType::NONE, "pn"));
} exp RB {
    ((Operator*)scope.back())->append($4);
    scope.pop_back();
}

exp: BOOL_VAL {
    $$ = (ASTNode*)$1;
} | NUM_VAL {
    $$ = (ASTNode*)$1;
} | variable {
    $$ = (ASTNode*)$1;
} | opr_exp {
    $$ = (ASTNode*)$1;
} | fun_exp {
    $$ = (ASTNode*)$1;
} | fun_call {
    $$ = (ASTNode*)$1;
} | if_exp {
    $$ = (ASTNode*)$1;
}

exps: exps exp { scope.back()->append($2); $$ = $1; } | exp

opr_exp: add | substract | multiply | divide | modulus | greater | less | equal
       | and_op | or_op | not_op

add: LB ADD {
    scope.append(new Operator(DataType::NUMBER, "+"));
} exp exps RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    $$->append($5);
    scope.pop_back();
}

substract: LB SUB {
    scope.append(new Operator(DataType::NUMBER, "-"));
} exp {
    scope.back()->append($4);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($6);
    scope.pop_back();
}

multiply: LB MUL {
    scope.append(new Operator(DataType::NUMBER, "*"));
} exp exps RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    $$->append($5);
    scope.pop_back();
}

divide: LB DIV {
    scope.append(new Operator(DataType::NUMBER, "/"));
} exp {
    scope.back()->append($4);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($6);
    scope.pop_back();
}

modulus: LB MOD {
    scope.append(new Operator(DataType::NUMBER, "%"));
} exp {
    scope.back()->append($4);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($6);
    scope.pop_back();
}

greater: LB GT {
    scope.append(new Operator(DataType::BOOLEAN, ">"));
} exp {
    scope.back()->append($4);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($6);
    scope.pop_back();
}

less: LB LT {
    scope.append(new Operator(DataType::BOOLEAN, "<"));
} exp {
    scope.back()->append($4);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($6);
    scope.pop_back();
}

equal: LB EQ {
    scope.append(new Operator(DataType::BOOLEAN, "=="));
} exp exps RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    $$->append($5);
    scope.pop_back();
}

and_op: LB AND {
    scope.append(new Operator(DataType::BOOLEAN, "&&"));
} exp exps RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    $$->append($5);
    scope.pop_back();
}

or_op: LB OR {
    scope.append(new Operator(DataType::BOOLEAN, "||"));
} exp exps RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    $$->append($5);
    scope.pop_back();
}

not_op: LB NOT {
    scope.append(new Operator(DataType::BOOLEAN, "!"));
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($4);
    scope.pop_back();
}

if_exp: LB IF {
    scope.append(new Operator(DataType::DYNAMIC, "?:"));
} exp {
    scope.back()->append($4);
} exp {
    scope.back()->append($6);
} exp RB {
    $$ = (Operator*)scope.back();
    $$->append($8);
    scope.pop_back();
}

def_stmt: LB DEF variable {
    if (scope.find($3->name) != nullptr)
        throw runtime_error(("'" + $3->name + "' has already been defined.").c_str());
} exp RB {
    Object* obj = Object::from_ast_node($5);
    obj->name = $3->name;
    scope.declare(obj);
}

variable: ID {
    auto obj_p = scope.find(*$1);
    if (obj_p != nullptr) $$ = obj_p;
    else $$ = new Object(*$1);
}

fun_exp: LB FUN LB {
    scope.append(new Function());
} fun_ids RB fun_body RB {
    $$ = (Function*)scope.back();
    $$->append($7);
    scope.pop_back();
}

fun_ids: fun_ids ID {
    ((Function*)scope.back())->params.push_back(*$2);
} | ;

fun_body: local_def_stmts exp {
    $$ = $2;
}

fun_call: LB fun_var {
    scope.append($2);
    int* param_index = new int(0);
    esp.push(param_index);
} params RB {
    $$ = (Function*)scope.back();
    auto param_index = (int*)esp.top();
    if ($4 != nullptr) {
        auto obj = Object::from_ast_node($4);
        obj->name = $$->params[(*param_index)++];
        scope.declare(obj);
    }
    delete param_index;
    esp.pop();
    scope.pop_back();
}

fun_var: fun_exp | fun_name { $$ = new Function(*$1); }

params: params exp {
    auto func = (Function*)scope.back();
    auto param_index = (int*)esp.top();
    if ($1 != nullptr) {
        auto obj = Object::from_ast_node($1);
        obj->name = func->params[(*param_index)++];
        scope.declare(obj);
    }
    $$ = $2;
} | {
    $$ = nullptr;
} ;

fun_name: ID {
    auto obj = scope.find(*$1);
    if (obj == nullptr)
        throw std::runtime_error("'" + *$1 + "' has not been defined.");
    $$ = (Function*)obj;
}

local_def_stmts: local_def_stmts local_def_stmt | ;

local_def_stmt: LB DEF variable exp RB {}

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