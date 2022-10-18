#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int items[1000];
    int top;
} stack;

void push(stack *s, int val) {
    s->items[++ s->top] = val;
}

int main() {
    stack *a = (stack*)malloc(sizeof(stack));
    stack *b = (stack*)malloc(sizeof(stack));
    a->top = -1;
    b->top = -1;
    push(a, 10);
    push(b, 20);
    return 0;
}