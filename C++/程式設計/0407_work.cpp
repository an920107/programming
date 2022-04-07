#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;  //資料成員 
    struct Node *next; //鏈結成員，存放下一節點的指標 
}; //typedef struct node Node; //將struct node 定義為Node型態 

int main(int argc, char** argv) {
    //宣告三個固定、不連續的位置給a、b、c 
    //node a,b,c;   //宣告a,b,c為node型態的變數 
    //node *ptr=&a; //宣告ptr，並將它指向節點a 
    struct Node a, b, c, d;  
    struct Node *ptr = &a;
    
    a.data = 12;  //設定節點a的data成員為12 
    a.next = &b;  //將節點a的next成員指向下一個節點，即b 
    b.data = 30;
    b.next = &c;
    c.data = 64;
    c.next = &d;
    d.data = 24;
    d.next = NULL;
    
    cout << endl;
    while(ptr != NULL) {                          //當ptr不是NULL時，則執行下列敘述 
        cout << "adress=" << ptr << " ";             //印出節點位址 
        cout << "data=" << ptr->data << " ";         //印出節點data 
        cout << "next=" << ptr->next << endl;        //印出節點next
        ptr = ptr->next;                       //將ptr指向下一個節點 
    } 
    
    system("pause");
    return 0;
}

Node* add(Node *ptr, Node *d) {
     
    return ptr;
}