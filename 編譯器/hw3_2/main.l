%{
#include <string.h>
#include <stdbool.h>
#include "main.tab.h"

int col_count = 0;

void col_add(int inc, bool pass_to_yacc) {
    col_count += inc;
    if (pass_to_yacc)
        yylval.col_count = col_count;
}

%}

%%

\+ { col_add(1, true); return ADD; }
\* { col_add(1, true); return MUL; }
\^T { col_add(2, true); return TRANS; }
"(" { col_add(1, true); return LB; }
")" { col_add(1, true); return RB; }
"[" { col_add(1, true); return LM; }
"]" { col_add(1, true); return RM; }
, { col_add(1, true); return COMMA; }
\n { col_add(1, true); return LF; }
-?[0-9]+ { col_add(strlen(yytext), false); yylval.inum = atoi(yytext); return NUM; }

[ \t] { col_add(1, true); }
\r { /** ignore */ }
. { col_add(1, true); return '.'; }

%%