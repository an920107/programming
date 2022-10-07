#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    struct stack *next;
    char data;
} stack;

stack *init() {
    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->next = NULL;
    new_stack->data = '\0';
    return new_stack;
}

bool empty(stack *s) {
    return s->next == NULL;
}

stack *push(stack *s, char c) {
    stack *new_s = (stack*)malloc(sizeof(stack));
    new_s->next = s;
    new_s->data = c;
    return new_s;
}

stack *pop(stack *s) {
    if (empty(s))
        return s;
    stack *new_s = s->next;
    free(s);
    return new_s;
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
    stack *str = init();
    stack *opts = init();
    stack *result = init();
    char input;
    while (input = getchar()) {
        if (input == '\n') break;
        str = push(str, input);
    }
    for (; !empty(str); str = pop(str)) {
        if (!priority(str->data)) // is number
            result = push(result, str->data);
        else {
            for (; !empty(opts) && priority(str->data) < priority(opts->data); opts = pop(opts))
                result = push(result, opts->data);
            opts = push(opts, str->data);
        }
    }
    for (; !empty(opts); opts = pop(opts))
        result = push(result, opts->data);
    for (; !empty(result); result = pop(result))
        printf("%c", result->data);
    printf("\n");
    return 0;
}