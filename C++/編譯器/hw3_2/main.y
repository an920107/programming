%{
#include "main.tab.h"

extern int yylex(void);
extern void yyerror(const char *);

void throw_error(int col) {
    printf("Semantic error on col %d\n", col);
    exit(0);
}

bool mtx_equal(mtx_t x, mtx_t y) {
    return x.row == y.row && x.col == y.col;
}

bool mtx_can_mul(mtx_t x, mtx_t y) {
    return x.col == y.row;
}

%}

%code requires {

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _mtx mtx_t;
struct _mtx {
    int row, col;
};

}

%union {
    mtx_t mtx;
    int inum;
    int col_count;
}

%left ADD
%left MUL
%right TRANS
%left LB RB
%token LM RM COMMA <inum>NUM LF
%type <mtx>matrix

%%

line: matrix LF;

matrix:
LM NUM COMMA NUM RM {
    if ($2 <= 0 || $4 <= 0)
        throw_error($<col_count>1);
    $$.row = $2;
    $$.col = $4;
}|

LB matrix RB {
    $$ = $2;
}|

matrix ADD matrix {
    if (!mtx_equal($1, $3))
        throw_error($<col_count>2);
    $$ = $1;
}|

matrix MUL matrix {
    if (!mtx_can_mul($1, $3))
        throw_error($<col_count>2);
    $$.row = $1.row;
    $$.col = $3.col;
}|

matrix TRANS {
    $$.row = $1.col;
    $$.col = $1.row;
};


%%

void yyerror(const char *message) {
    throw_error(yylval.col_count);
    exit(0);
}

int main(int argc, char **argv) {
    yyparse();
    printf("Accepted\n");
    return 0;
}