%{
#include "main.tab.h"
%}

%%

\+ { return ADD; }
\- { return SUB; }
\* { return MUL; }
\/ { return DIV; }
[1-9][0-9]*(\.[0-9]*)?|\.[0-9]+|0\.[0-9]* { yylval.num = atof(yytext); return NUM; }
[ \t\r\n] { /** ignore */ }
. { return '~'; }

%%