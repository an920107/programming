#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define queue_T char

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
    que->front->data = NULL;
    free(ori_node);
    return true;
}

void clear_q(queue *que) {
    while (pop_q(que));
}

queue_T peep_q(queue *que) {
    return que->front->next->data;
}