template<typename T> class LinkedList {
private:

    struct Node {
        T value;
        Node* next;

        Node() {
            next = nullptr;
        }
    };

    Node* front, rear;
    int size;

    Node* getNode(int index) {
        Node* tmp = front;
        for (int i = 0; i < index; i ++) {
            tmp = tmp->next;
        }
        return tmp;
    }

public:

    LinkedList() {
        front = new Node;
        rear = front;
        size = 0;
    }

    ~LinkedList() {
        Node* tmp;
        while (front->next != nullptr) {
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    void insert(T value) {
        Node* newnode = new Node;
        newnode->data = value;
        rear->next = newnode;
        rear = newnode;
        ++ size;
    }

    void insert(int index, T value) {
        if (index >= size) return;
        if (index == size - 1) {
            insert(value);
            return;
        }
        Node* tmp = getNode(index);
        Node* newnode = new Node;
        newnode->value = value;
        newnode->next = tmp->next;
        tmp->next = newnode;
        ++ size;
    }

    void remove() {
        remove(size - 1);
    }

    void remove(int index) {
        if (index >= size) return;
        Node* tmp = getNode(index);
        Node* toRemove = tmp;
        tmp = tmp->next;
        if (index == 0) front = tmp;
        delete toRemove;
        -- size;
    }

    T get(int index) {
        if (index >= size) return;
        return getNode(index)->next->value;
    }

    int size() {
        return size;
    }

};