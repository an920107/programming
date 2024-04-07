%{
#include "main.tab.h"
%}
%%

-?[1-9][0-9]*|0 {
    yylval = atoi(yytext);
    return NUM;
}

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }

[ \t\r\n] { /** ignore */ }
. { return '~'; }

%%