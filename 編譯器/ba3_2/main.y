%{
#include "main.tab.h"
extern int yylex(void);
extern void yyerror(const char*);

#define STACK_CAP 10
stack_t stack;
%}

%code requires {
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _stack stack_t;
struct _stack {
    int size;
    int* data;
};

void stack_push(stack_t*, int);
int stack_pop(stack_t*);
void stack_print(stack_t*);
}

%token ADD SUB MUL DIV
%token NUM

%%

operands: operands operand {
    stack_print(&stack);
} | ;

operand: NUM {
    stack_push(&stack, $1);
} | ADD {
    int y = stack_pop(&stack);
    int x = stack_pop(&stack);
    stack_push(&stack, x + y);
} | SUB {
    int y = stack_pop(&stack);
    int x = stack_pop(&stack);
    stack_push(&stack, x - y);
} | MUL {
    int y = stack_pop(&stack);
    int x = stack_pop(&stack);
    stack_push(&stack, x * y);
} | DIV {
    int y = stack_pop(&stack);
    int x = stack_pop(&stack);
    stack_push(&stack, x / y);
}

%%

void yyerror(const char* message) {
    printf("%s\n", message);
    exit(0);
}

void stack_push(stack_t* s, int value) {
    if (s->size >= STACK_CAP - 1)
        yyerror("Runtime Error: The push will lead to stack overflow.");
    s->data[++s->size] = value;
}

int stack_pop(stack_t* s) {
    if (s->size < 0)
        yyerror("Runtime Error: The pop will lead to stack underflow.");
    return s->data[s->size--];
}

void stack_print(stack_t* s) {
    printf("The contents of the stack are: ");
    int i;
    for (i = 0; i <= s->size; i++) {
        printf("%d", s->data[i]);
        printf(i == s->size ? "\n" : " ");
    }
}

int main(int argc, char** argv) {
    stack.size = -1;
    stack.data = (int*)malloc(sizeof(int) * STACK_CAP);
    yyparse();
    return 0;
}