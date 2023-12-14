%{
    int lb_count = 0;

    void print_tab(int count) {
        while (count--)
            printf("\t");
    }
%}

LB      \{
RB      \}
EOL     \n
SPC     [\t ]

%x NEWLINE
%%
{LB} {
    ECHO;
    lb_count++;
}

{RB} {
    ECHO;
    lb_count--;
}

{EOL} {
    ECHO;
    BEGIN NEWLINE;
}

<NEWLINE>{SPC} {}

<NEWLINE>{RB}+ {
    lb_count -= yyleng;
    print_tab(lb_count);
    ECHO;
    BEGIN 0;
}

<NEWLINE>. {
    print_tab(lb_count);
    yyless(0);
    BEGIN 0;
}

%%
int main(int argc, char *argv[]) {
    yylex();
    return 0;
}
