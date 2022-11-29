#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define list_T char

typedef struct {
    struct node *next;
    list_T data;
} node;

typedef struct {
    struct node *begin, *end;
    int size;
} list;

list *init() {
    list *lst = (list*)malloc(sizeof(list));
    lst->begin = NULL;
    lst->end = NULL;
}

void emplace_back(list *lst, list_T val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->next = lst->end;
    lst->size ++;
}