%{
#include "main.tab.h"
%}

%%

\+ { return ADD; }
\- { return SUB; }
\* { return MUL; }
\/ { return DIV; }
"(" { return LB; }
")" { return RB; }
\n { return LF; }
[0-9]+(\.[0-9]+)? { yylval.num = atof(yytext); return NUM; }

%%