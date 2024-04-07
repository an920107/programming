%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void);
extern void yyerror(const char *);
%}

%union {
    double num;
}

%left ADD SUB
%left MUL DIV
%nonassoc LB RB
%token <num>NUM LF
%type <num>eval

%%

stmts:
stmts eval LF { printf("%.1lf\n", $2); }|
stmts LF | ;

eval:
LB eval RB { $$ = $2; }|
eval ADD eval { $$ = $1 + $3; }|
eval SUB eval { $$ = $1 - $3; }|
eval MUL eval { $$ = $1 * $3; }|
eval DIV eval { $$ = $1 / $3; }|
NUM { $$ = $1; };

%%

void yyerror(const char * message) {
    printf("%s\n", message);
    exit(0);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}