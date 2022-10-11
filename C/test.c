#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main() {
    char ch;
    queue *que = init();
    while (ch = getchar()) {
        if (ch == '\n') break;
        push(que, ch);
    }
    for (; !empty(que); pop(que))
        putchar(peep(que));
    return 0;
}