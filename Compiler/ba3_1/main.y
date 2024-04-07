%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void);
extern void yyerror(const char *);
%}

%union {
    float num;
}

%left ADD SUB
%left MUL DIV
%token <num>NUM
%type <num>eval

%%

stmt: eval { printf("%.3f\n", $1); }

eval:
eval ADD eval {
    $$ = $1 + $3;
} |
eval SUB eval {
    $$ = $1 - $3;
} |
eval MUL eval {
    $$ = $1 * $3;
} |
eval DIV eval {
    if ($3 == 0) {
        yyerror("");
    }
    $$ = $1 / $3;
} |
NUM {
    $$ = $1;
}

%%

void yyerror(const char * message) {
    printf("Invalid Value\n");
    exit(0);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}