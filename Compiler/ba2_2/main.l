WORD        [A-Z][a-z]+
UWORD       [A-Z][A-Z]+
BOOK_NAME   {WORD}(_{WORD})*
AUTHOR      {UWORD},[ ]{WORD}-{WORD}
DIG4        [0-9][0-9][0-9][0-9]
DIG2        [0-9][0-9]
SN          (978)-[0-9]-{DIG2}{DIG4}-{DIG2}-[0-9]

%x INIT BSC ASC DSC
%%

. {yyless(0); BEGIN INIT;}

<INIT>{BOOK_NAME} {
    printf("Book name:%s\n", yytext);
    BEGIN BSC;
}

<INIT>[\r\n]* {BEGIN 0;}
<INIT>. {}

<INIT,BSC>{AUTHOR} {
    printf("Author:%s\n", yytext);
    BEGIN ASC;
}

<INIT,BSC>[\r\n]* {BEGIN 0;}
<INIT,BSC>. {}

<INIT,BSC,ASC>{DIG4}\/{DIG2}\/{DIG2} {
    char tmp;
    int y, m, d;
    int error = 0;
    sscanf(yytext, "%d%c%d%c%d", &y, &tmp, &m, &tmp, &d);
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) error = 1;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) error = 1;
    } else if (m == 2) {
        if (d > 29) error = 1;
    } else error = 1;

    if (!error) printf("Publication date:%s\n", yytext);
    BEGIN DSC;
}

<INIT,BSC,ASC>[\r\n]* {BEGIN 0;}
<INIT,BSC,ASC>. {}

<INIT,BSC,ASC,DSC>{SN} {
    printf("ISBN:%s\n", yytext);
    BEGIN 0;
}

<INIT,BSC,ASC,DSC>[\r\n]* {BEGIN 0;}
<INIT,BSC,ASC,DSC>. {}

%%

int main() {
    yylex();
    return 0;
}
