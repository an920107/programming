#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createList(int*, int);
Node *insert(Node*, int);
void printList(Node*);
void freeList(Node*);

int main(int argc, char** argv) {
	Node *first;
	int arr[] = {14, 27, 32, 46};
	int data = 36;
	first = createList(arr, 4);
	printList(first);
	first = insert(first, data);
	printList(first);
	freeList(first);
	return 0;
}

Node *createList(int *arr, int len) {
	int i;
	Node *first, *current, *previous;
	for(i = 0; i < len; i++){
		current = (Node *)malloc(sizeof(Node));
		current->data = arr[i];
		if (i == 0) {
			first = current;
		} else {
			previous->next = current;
		}
		current->next = NULL;
		previous = current;
	}
	return first;
}

void printList(Node *first) {
	Node *node = first;
	if (first == NULL) {
		printf("List is empty");
	} else {
		while (node!=NULL) {
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}

void freeList(Node *first) {
	Node *ptr, *tmp;
	ptr = first;
	while (ptr != NULL) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

Node *insert(Node *first, int data) {
	Node *current, *previous;
	Node *newnode;
	current = first;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
        if (data > current->data) continue;
        newnode = (Node *)malloc(sizeof(Node));
        previous->next = newnode;
        newnode->data = data;
        newnode->next = current;
    }
    return first;
}
