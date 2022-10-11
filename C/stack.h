#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define stack_T char

typedef struct node {
    struct node *prev;
    stack_T data;
} node;

typedef struct stack {
    node *bot, *top;
} stack;

stack *init() {
    stack *stk = (stack*)malloc(sizeof(stack));
    stk->bot = (node*)malloc(sizeof(node));
    stk->bot->prev = NULL;
    stk->top = stk->bot;
    return stk;
}

bool empty(stack *stk) {
    return stk->top == stk->bot;
}

void push(stack *stk, stack_T val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->prev = stk->top;
    new_node->data = val;
    stk->top = new_node;
}

bool pop(stack *stk) {
    if (empty(stk)) return false;
    node *ori_node = stk->top;
    stk->top = ori_node->prev;
    free(ori_node);
    return true;
}

stack_T peep(stack *stk) {
    return stk->top->data;
}

void clear(stack *stk) {
    while (pop(stk));
}

void dump(stack *to, stack *from) {
    for (; !empty(from); pop(from))
        push(to, peep(from));
}