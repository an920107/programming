#include <bits/stdc++.h>
using namespace std;

#define MAXQUEUE 5

struct guest
{
    char name;
    int number;
};
struct Queue 
{
    int front;
    int rear;
    struct guest items[MAXQUEUE];
};

int lengthOfQ(struct Queue *q){
    if(q -> front > q -> rear){
       return q -> rear + 1 + MAXQUEUE - q ->front;
    }
    else{
        return q -> rear - q -> front;
    }
}

bool isEmpty(struct Queue *q) 
{
    return (q -> front == q -> rear);
}

bool isFull(struct Queue *q)
{
    return lengthOfQ(q) == MAXQUEUE;
}

void addQ(struct Queue *q, struct guest *g)
{
    if(isFull(q)){
        return;
    }
    else{
        q -> rear = (q -> rear + 1) % MAXQUEUE;
        q -> items[q -> rear] = *g;
    }
}

void deleteQ(struct Queue *q)
{
    q -> front = (q -> front + 1) % MAXQUEUE;
}


int sumOfGuest(struct Queue *q)
{
    int sum = 0;
    int i;
    if(!isEmpty(q)){
        for(i = 0; i < lengthOfQ(q); i ++){
            sum += q -> items[(i + q -> front + 1) % MAXQUEUE].number;
        }
    }
    return sum;
}
void sameGuest(struct Queue *q, struct guest *g){
    int i;
    bool isSame = false;
    for(i = 0; i < lengthOfQ(q); i ++){
        if(q ->items[(i + q -> front + 1) % MAXQUEUE].name == g -> name){
            isSame = true;
        }
    }
    if(!isSame){
        addQ(q, g);
    }
}
void behavior(struct Queue *q, struct guest *g){
    while(1){
        int n;
        scanf("%d", &n);

        if(n == -1) break;

        switch (n) {
            case 1:
                scanf(" %c %d", &(g -> name), &(g -> number));
                sameGuest(q,g);
                break;
            case 2:
                cout << sumOfGuest(q) << '\n';
                break;
            case 3:
                cout << q -> items[(q -> front + 1) % MAXQUEUE].name << '\n';
                break;
            case 4:
                deleteQ(q);
                break;
            default:
                cout << "error\n";
                break;
        }
    } 
}


int main()
{
    // struct Queue *myQueue;
    // myQueue->front = -1;
    // myQueue->rear = -1;
    // struct guest *myGuest;
    
    // behavior(myQueue, myGuest);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    struct Queue myQueue;
    myQueue.front = -1;
    myQueue.rear = -1;
    struct guest myGuest;
    
    behavior(&myQueue, &myGuest);
}