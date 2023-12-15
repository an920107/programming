%{
#include "main.tab.h"

#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif
%}

%option noyywrap

%%

"(" { if (is_debug) cerr << "[LB]\n"; return LB; }
")" { if (is_debug) cerr << "[RB]\n"; return RB; }
"+" { if (is_debug) cerr << "[ADD]\n"; return ADD; }
"-" { if (is_debug) cerr << "[SUB]\n"; return SUB; }
"*" { if (is_debug) cerr << "[MUL]\n"; return MUL; }
"/" { if (is_debug) cerr << "[DIV]\n"; return DIV; }
mod { if (is_debug) cerr << "[MOD]\n"; return MOD; }
">" { if (is_debug) cerr << "[GT]\n"; return GT; }
"<" { if (is_debug) cerr << "[LT]\n"; return LT; }
"=" { if (is_debug) cerr << "[EQ]\n"; return EQ; }
and { if (is_debug) cerr << "[AND]\n"; return AND; }
or { if (is_debug) cerr << "[OR]\n"; return OR; }
not { if (is_debug) cerr << "[NOT]\n"; return NOT; }
define { if (is_debug) cerr << "[DEF]\n"; return DEF; }
fun { if (is_debug) cerr << "[FUN]\n"; return FUN; }
if { if (is_debug) cerr << "[IF]\n"; return IF; }
print\-num { if (is_debug) cerr << "[PRINT_N]\n"; return PRINT_N; }
print\-bool { if (is_debug) cerr << "[PRINT_B]\n"; return PRINT_B; }

#[tf] {
    yylval.bool_val = (yytext[1] == 't');
    if (is_debug) cerr << "[BOOL_VAL]\n";
    return BOOL_VAL;
}

-?[1-9][0-9]*|0 {
    if (is_debug) cerr << "[NUM_VAL]\n";
    Python py;
    py.commit(string("print(-2**31<=") + yytext + string("<2**31)"));
    if (py.exec() == "False\n")
        throw domain_error("the number is out of bounds.");
    yylval.num_val = atoi(yytext);
    return NUM_VAL;
}

[a-z][a-z0-9\-]* {
    if (is_debug) cerr << "ID\n";
    yylval.id_name = new string(yytext);
    return ID;
}

[ \r\t\n]+ { /** ignore */ }

. {
    if (is_debug) cerr << "[ERR]\n";
    throw runtime_error(
        ("unexpected character: '" + string(yytext) + "'.").c_str());
}

%%