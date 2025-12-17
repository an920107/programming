%{
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include "include/python.hpp"
#include "include/ast.hpp"
using namespace std;

#ifndef _YACC_DECLARE_
#define _YACC_DECLARE_
#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif
#endif

#include "main.tab.h"
%}

%option noyywrap

%%

"(" { if (is_debug) cout << "[LB] "; return LB; }
")" { if (is_debug) cout << "[RB] "; return RB; }
"+" { if (is_debug) cout << "[ADD] "; return ADD; }
"-" { if (is_debug) cout << "[SUB] "; return SUB; }
"*" { if (is_debug) cout << "[MUL] "; return MUL; }
"/" { if (is_debug) cout << "[DIV] "; return DIV; }
mod { if (is_debug) cout << "[MOD] "; return MOD; }
">" { if (is_debug) cout << "[GT] "; return GT; }
"<" { if (is_debug) cout << "[LT] "; return LT; }
"=" { if (is_debug) cout << "[EQ] "; return EQ; }
and { if (is_debug) cout << "[AND] "; return AND; }
or { if (is_debug) cout << "[OR] "; return OR; }
not { if (is_debug) cout << "[NOT] "; return NOT; }
define { if (is_debug) cout << "[DEF] "; return DEF; }
fun { if (is_debug) cout << "[FUN] "; return FUN; }
if { if (is_debug) cout << "[IF] "; return IF; }
print\-num { if (is_debug) cout << "[PRINT_N] "; return PRINT_N; }
print\-bool { if (is_debug) cout << "[PRINT_B] "; return PRINT_B; }

#[tf] {
    yylval.bool_val = yytext[1] == 't';
    if (is_debug) cout << "[BOOL_VAL] ";
    return BOOL_VAL;
}

-?[1-9][0-9]*|0 {
    if (is_debug) cout << "[NUM_VAL] ";
    Python py;
    py.commit(string("print(-2**31<=") + yytext + string("<2**31)"));
    if (py.exec() == "False\n")
        throw domain_error("the number is out of bounds.");
    yylval.num_val = atoi(yytext);
    return NUM_VAL;
}

[a-z][a-z0-9\-]* {
    if (is_debug) cout << "[ID] ";
    yylval.text = new string(yytext);
    return ID;
}

[\r\n]+ {
    /** ignore */
    if (is_debug) cout << "\n";
}

[ \t]+ { /** ignore */ }

. {
    if (is_debug) cout << "[ERR] ";
    throw runtime_error(
        ("Unexpected character: '" + string(yytext) + "'.").c_str());
}

%%