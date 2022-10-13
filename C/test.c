#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T char

typedef struct node {
    struct node *prev, *next;
    T data;
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

void push_s(stack *stk, T val) {
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

T peep_s(stack *stk) {
    return stk->top->data;
}

void clear_s(stack *stk) {
    while (pop_s(stk));
}

void dump_s(stack *to, stack *from) {
    for (; !empty_s(from); pop_s(from))
        push_s(to, peep_s(from));
}

typedef struct queue {
    node *front, *rear;
} queue;

queue *init_q() {
    queue *que = (queue*)malloc(sizeof(queue));
    que->front = (node*)malloc(sizeof(node));
    que->front->next = NULL;
    que->rear = que->front;
    return que;
}

bool empty_q(queue *que) {
    return que->front == que->rear;
}

void push_q(queue *que, T val) {
    que->rear->next = (node*)malloc(sizeof(node));
    que->rear = que->rear->next;
    que->rear->next = NULL;
    que->rear->data = val;
}

bool pop_q(queue *que) {
    if (empty_q(que)) return false;
    node *ori_node = que->front;
    que->front = que->front->next;
    que->front->data = '\0';
    free(ori_node);
    return true;
}

T peep_q(queue *que) {
    return que->front->next->data;
}

int main() {
    bool flag = false;
    int n, num, i;
    stack *stk = init_s();
    queue *que = init_q();
	printf("Please enter an interger N (N > 0):\n");
    scanf("%d", &n);
    printf("Please enter %d intergers:\n", n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i ++)
        scanf("%d", (arr + i));
    printf("The stack now contains");
    for (i = 0; i < n; i ++) {
        printf(" %d", arr[i]);
        push_s(stk, arr[i]);
    }
    printf("\nPlease enter a query integer:\n");
    scanf("%d", &num);
    while (!empty_s(stk)) {
        push_q(que, peep_s(stk));
        pop_s(stk);
        if (peep_q(que) == num) {
            flag = true;
            break;
        }
        pop_q(que);
    }
    printf(flag ? "%d has been found\n" : "%d cannot be found\n", num);
	return 0;
}