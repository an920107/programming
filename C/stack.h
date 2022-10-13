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

stack *init_s() {
    stack *stk = (stack*)malloc(sizeof(stack));
    stk->bot = (node*)malloc(sizeof(node));
    stk->bot->prev = NULL;
    stk->top = stk->bot;
    return stk;
}

bool empty_s(stack *stk) {
    return stk->top == stk->bot;
}

void push_s(stack *stk, stack_T val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->prev = stk->top;
    new_node->data = val;
    stk->top = new_node;
}

bool pop_s(stack *stk) {
    if (empty_s(stk)) return false;
    node *ori_node = stk->top;
    stk->top = ori_node->prev;
    free(ori_node);
    return true;
}

stack_T peep_s(stack *stk) {
    return stk->top->data;
}

void clear_s(stack *stk) {
    while (pop_s(stk));
}

void dump_s(stack *to, stack *from) {
    for (; !empty_s(from); pop_s(from))
        push_s(to, peep_s(from));
}