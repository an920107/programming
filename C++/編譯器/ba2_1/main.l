%%

^[0-9]*\.[0-9]*$ {
    // .123123  12312. 123123.123123
    if (yyleng == 1) REJECT;
    ECHO;
    printf(" FLOAT");
}

^[0-9]+$ {
    ECHO;
    printf(" INTERGER");
}

^(\"[^\"]*\")|(\'[^\']*\')$ {
    // ("[^"]*")|('[^']*')
    ECHO;
    printf(" STRING");
}

^[a-zA-Z_][0-9a-zA-Z_]*$ {
    ECHO;
    printf(" VARIABLE");
}

^.*\n {}

%%

int main() {
    yylex();
    return 0;
}
