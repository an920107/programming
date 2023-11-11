%{
    int lb_count = 0;
%}

LB      \{
RB      \}
EOL     \n
LINE    .*({EOL})

%%

<<EOF>> { yyless(); ECHO('\n'); }
{LINE} { printf("%d\n", lb_count++); }

%%

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}
