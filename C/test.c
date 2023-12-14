#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* yytext = "-1000000000000";
    char* pre = "python -c \"print(-2**31<=";
    char* post = "<2**31)\"";
    int command_len = strlen(pre) + strlen(yytext) + strlen(post);
    char* command = (char*)malloc(command_len + 1);
    strcpy(command, pre);
    strcpy(command + strlen(pre), yytext);
    strcpy(command + strlen(pre) + strlen(yytext), post);
    command[command_len] = '\0';
    system(command);

    return 0;
}