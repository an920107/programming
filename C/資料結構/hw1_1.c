#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    struct stack *next;
    float data;
} stack;

stack *push(stack *s, float c) {
    stack *new_s = (stack*)malloc(sizeof(stack));
    new_s->next = s;
    new_s->data = c;
    return new_s;
}

stack *pop(stack *s) {
    stack *new_s = s->next;
    free(s);
    return new_s;
}

stack *count(stack *s, char opt) {
    float y = s->data;
    s = pop(s);
    float x = s->data;
    s = pop(s);
    switch (opt) {
        case '*':
            return push(s, x * y);
        case '/':
            return push(s, x / y);
        case '+':
            return push(s, x + y);
        case '-':
            return push(s, x - y);
        default:
            return NULL;
    }
}

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    stack *stk = (stack*)malloc(sizeof(stack));
    stk->next = NULL;
    stk->data = .0;

    char input;
    while (input = getchar()) {
        if (input == '\n') break;
        if (stk->next == NULL || is_num(input))
            stk = push(stk, (float)(input - 48));
        else stk = count(stk, input);
    }
    printf("%.2f\n", stk->data);

    return 0;
}