#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct definitions
typedef struct node node_t;
struct node {
    node_t* last;
    int value;
};

typedef struct stack stack_t;
struct stack {
    node_t* top;
};

typedef struct pair pair_t;
struct pair {
    int x, y;
};

// method definitions
bool stack_is_empty(stack_t* s) { return s->top == NULL; }

void stack_push(stack_t* s, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->last = s->top;
    new_node->value = value;
    s->top = new_node;
}

void stack_pop(stack_t* s) {
    if (stack_is_empty(s)) return;
    s->top = s->top->last;
}

int stack_top(stack_t* s) {
    if (stack_is_empty(s)) return;
    return s->top->value;
}

pair_t get_params(stack_t* s) {
    pair_t result;
    if (stack_is_empty(s)) yyerror();
    result.x = stack_top(s);
    stack_pop(s);
    if (stack_is_empty(s)) yyerror();
    result.y = stack_top(s);
    stack_pop(s);
    return result;
}

int get_param(stack_t* s) {
    if (stack_is_empty(s)) yyerror();
    int result = stack_top(s);
    stack_pop(s);
    return result;
}

// initialization

int main() {
    strlen("123");
    return 0;
}