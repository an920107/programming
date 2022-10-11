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

queue *init() {
    queue *que = (queue*)malloc(sizeof(queue));
    que->front = (node*)malloc(sizeof(node));
    que->front->next = NULL;
    que->rear = que->front;
    return que;
}

bool empty(queue *que) {
    return que->front == que->rear;
}

void push(queue *que, queue_T val) {
    que->rear->next = (node*)malloc(sizeof(node));
    que->rear = que->rear->next;
    que->rear->next = NULL;
    que->rear->data = val;
}

bool pop(queue *que) {
    if (empty(que)) return false;
    node *ori_node = que->front->next;
    que->front->next = que->front->next->next;
    free(ori_node);
    return true;
}

queue_T peep(queue *que) {
    return que->front->data;
}