#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node* add(Node*, Node*);

int main(int argc, char** argv) {
    struct Node a, b, c, d; 
    struct Node *ptr = &a;
    
    a.data = 12;
    a.next = &b;
    b.data = 30;
    b.next = &c;
    c.data = 64;
    
    add(&c, &d);
    d.data = 24;
    
    cout << endl;
    while(ptr != NULL) {
        cout << "adress=" << ptr << " ";
        cout << "data=" << ptr->data << " ";
        cout << "next=" << ptr->next << endl;
        ptr = ptr->next;
    } 
    
    system("pause");
    return 0;
}

Node* add(Node *ptr, Node *d) {
    ptr->next = d;
    d->next = NULL;
    return ptr;
}