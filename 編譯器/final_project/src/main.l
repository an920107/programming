%{
#include "main.tab.h"
%}

%option noyywrap

%%

[ ]*"("[ ]* { return LB; }
[ ]*")"[ ]* { return RB; }
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
mod { return MOD; }
">" { return GT; }
"<" { return LT; }
"=" { return EQ; }
and { return AND; }
or { return OR; }
not { return NOT; }
define { return DEF; }
fun { return FUN; }
if { return IF; }
print\-num { return PRINT_N; }
print\-bool { return PRINT_B; }

#[tf] {
    yylval.bool_val = (yytext[1] == 't');
    return BOOL_VAL;
}

-?[1-9][0-9]*|0 {
    Python py;
    py.commit(string("print(-2**31<=") + yytext + string("<2**31)"));
    if (py.exec() == "False\n")
        throw domain_error("the number is out of bounds");
    yylval.num_val = atoi(yytext);
    return NUM_VAL;
}

[a-z][a-z0-9\-]* {
    yylval.var = new Variable(string(yytext), VarType::DYNAMIC);
    return ID;
}

[ \r\t\n]+ { return SEP; }
. { return '~'; }

%%