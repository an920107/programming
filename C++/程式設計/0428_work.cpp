#include <bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *begin;

public:
    LinkedList();
    ~LinkedList();
    void addLast(int);
    void remove(int);
    friend ostream& operator<<(ostream&, LinkedList);
};

int main() {
    LinkedList llist;
    const int arr[] = {12, 43, 56, 34, 98, 76, 43, 23};
    for (const int x : arr) {
        llist.addLast(x);
    }
    cout << llist << "\n";
    llist.remove(12);
    llist.remove(34);
    llist.remove(24);
    cout << llist << "\n";
    system("pause");
    return 0;
}

LinkedList::LinkedList() {
    begin = (Node *)malloc(sizeof(Node));
    begin->next = nullptr;
}

LinkedList::~LinkedList() {

}

void LinkedList::addLast(int data) {
    Node *previous = this->begin;
    while (previous->next != nullptr) {
        previous = previous->next;
    }
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->next = nullptr;
    previous->next = current;
}

void LinkedList::remove(int data) {
    Node *previous = this->begin, *current;
    while (previous->next != nullptr) {
        current = previous->next;
        if (current->data == data) {
            previous->next = current->next;
            delete current;
            break;
        }
        previous = current;
    }
}

ostream& operator<<(ostream& os, LinkedList obj) {
    LinkedList::Node *previous = obj.begin, *current;
    os << "[ ";
    while (true) {
        if (previous->next != nullptr) {
            current = previous->next;
            os << current->data;
            if (current->next != nullptr)
                os << ", ";
            previous = current;
        }
        else break;
    }
    os << " ]";
    return os;
}