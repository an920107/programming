%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylex(void);
extern void yyerror(const char*);
%}

%%

%%

void yyerror(const char* message) {
    printf("%s\n", message);
}

int main(int argc, char** argv) {
    yyparse();
    return 0;
}