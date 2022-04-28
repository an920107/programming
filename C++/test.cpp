#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *createList(int *, int);
void printList(Node *);
void freeList(Node *);
Node *deleteList(Node *, int);

int main(){
    Node *first;
    int arr[] = {12, 43, 56, 34, 98, 76, 43, 24};
    first = createList(arr, 8);
    cout << "origin array: ";
    printList(first);

    cout << "Delete num = ";
    int a;
    cin >> a;//34

    first = deleteList(first, a);
    cout << "thenew array: ";
    system("pause");
    printList(first);
    system("pause");
    freeList(first);

    system("pause");
    return 0;

}

Node *createList(int *arr, int len){
    Node *first, *current, *previous;
    for(int i = 0; i < len; i ++){
        current = (Node *)malloc(sizeof(Node));
        current->data = arr[i];
        if(i == 0){
            first = current;
        }
        else{
            previous->next = current;
        }
        current ->next = NULL;
        previous = current;
    }
    return first;
}

void printList(Node *first){
    Node *node = first;
    if(first = NULL){
        printf("List is empty\n");
    }
    else{
        while(node != NULL){

            cout << node->data << " ";
            node = node->next;
        }
        cout << '\n';
    }
}

void freeList(Node *first){
    Node *ptr, *tmp;
    ptr = first;
    while(ptr != NULL){
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    return;
}

Node *deleteList(Node * first, int num){
    Node *ptr = first, *tmp;
    while(ptr != NULL){
        if(ptr->data == num){
            tmp = ptr;
            ptr = ptr ->next;
        }
        cout << "now ptr = " << ptr->data;
        ptr = ptr->next;
        if(ptr != NULL){
            cout << " next ptr = " << ptr->data << '\n';
        }
        if(ptr == NULL){
            cout << " next ptr = NULL\n";
        }
    }
    return first;
}