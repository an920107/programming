#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;  
	struct node *next;
};
typedef struct node Node;

Node *creates();
Node *addstack(Node *, int);
Node *deletestack(Node *);
void printList(Node *);

int main(int argc, char** argv) {
	Node *sTop;
	sTop = creates();
	sTop = addstack(sTop, 5);
	sTop = addstack(sTop, 6);
	sTop = deletestack(sTop);
	sTop = addstack(sTop, 8);
	sTop = addstack(sTop, 10);
	
	printList(sTop);
	
	system("pause");
	return 0;
}

Node* creates(){
	return NULL;
}

Node *addstack(Node *Top, int item){
	Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = Top;
    Top = newnode;
	return Top;
}

Node *deletestack(Node *Top){
	Node *temp = Top;
	Top = Top->next;
    delete temp;
	return Top;
}

void printList(Node *sTop){
	Node *node  = sTop;
	while(node != NULL){
		printf("%3d", node -> data);
		node = node -> next;
	}
	printf("\n");
}