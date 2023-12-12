%{
#include "main.tab.h"
%}

%%

load { return LOAD; }
add { return ADD; }
sub { return SUB; }
mul { return MUL; }
mod { return MOD; }
inc { return INC; }
dec { return DEC; }
[ ] { /** ignore */ }
\r { /** ignore */ }
\n { return LF; }

-?[0-9]+ {
    yylval = atoi(yytext);
    return NUM;
}

%%