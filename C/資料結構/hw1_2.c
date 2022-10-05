#include <stdio.h>

typedef struct stack {
    struct stack *next;
    char data;
} stack;

stack *s_push(stack *s, char c) {
    stack *new_s = (stack*)malloc(sizeof(stack));
    new_s->next = s;
    new_s->data = c;
    return new_s;
}

stack *s_pop(stack *s) {
    stack *new_s = s->next;
    free(s);
    return new_s;
}

queue *q_push(queue *q, char c) {
    
}

int priority(char c) {
    switch (c) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main() {
    stack *stk = (stack*)malloc(sizeof(stack));
    stk->next = NULL;
    stk->data = '\0';

    queue *que = (queue*)malloc(sizeof(queue));
    

    char input;
    while (input = getchar()) {
        if (input == "\n") break;
        if (!priority(input))
        if (stk->next == NULL || priority(input) >= priority(stk->data))
            stk = s_push(stk, input);
    }

    return 0;
}