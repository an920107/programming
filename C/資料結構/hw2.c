#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * definination of customer
 */

typedef struct customer {
    char id;
    int count;
} customer;

/**
 * definination of queue
 */

#define queue_T customer

typedef struct node {
    struct node *next;
    queue_T data;
} node;

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

void push_q(queue *que, queue_T val) {
    que->rear->next = (node*)malloc(sizeof(node));
    que->rear = que->rear->next;
    que->rear->next = NULL;
    que->rear->data = val;
}

bool pop_q(queue *que) {
    if (empty_q(que)) return false;
    node *ori_node = que->front;
    que->front = que->front->next;
    free(ori_node);
    return true;
}

void clear_q(queue *que) {
    while (pop_q(que));
}

queue_T peep_q(queue *que) {
    return que->front->next->data;
}

/** 
 * custom queue functions
 */

bool exist_q(queue *que, char val) {
    if (empty_q(que)) return false;
    if (que->rear->data.id == val) return true;
    node *nd = que->front->next;
    for (; nd != que->rear; nd = nd->next)
        if (nd->data.id == val)
            return true;
    return false;
}

int sum_q(queue *que) {
    if (empty_q(que)) return 0;
    int sum = 0;
    node *nd = que->front->next;
    for (; nd != que->rear; nd = nd->next)
        sum += nd->data.count;
    sum += nd->data.count;
    return sum;
}

/** 
 * main
 */

#define QUEUE_MAX 5

int main() {
    bool exitFlag = false;
    int cmd, acc = 0;
    customer cus;
    queue *que = init_q();
    while (!exitFlag && ~scanf("%d", &cmd)) {
        switch (cmd) {
            case 1:
                scanf(" %c %d", &cus.id, &cus.count);
                if (acc < QUEUE_MAX && !exist_q(que, cus.id)) {
                    push_q(que, cus);
                    acc ++;
                }
                break;
            case 2:
                printf("%d\n", sum_q(que));
                break;
            case 3:
                if (!empty_q(que))
                    printf("%c\n", peep_q(que).id);
                break;
            case 4:
                if (!empty_q(que))
                    pop_q(que);
                break;
            case -1:
                exitFlag = true;
                break;
            default:
                printf("error\n");
                break;
        }

    }
    return 0;
}