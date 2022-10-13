#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
} node;

node *n;

void foo1(int &num) {
    n->data = num;
}

void foo2(int &num) {
    (*n).data = num;
}

int main() {

    auto start = clock();
    auto end = clock();
    int avg;
    n = (node*)malloc(sizeof(node));

    avg = 0;
    for (int t = 1; t <= 10; ++ t) {
        start = clock();
        for (int i = 0; i < 1E9; ++ i)
            foo1(i);
        end = clock();
        cout << t << "\t" << end - start << "\n";
        avg += end - start;
    }
    cout << "avg:\t" << avg / 10.0 << "\n\n";

    avg = 0;
    for (int t = 1; t <= 10; ++ t) {
        start = clock();
        for (int i = 0; i < 1E9; ++ i)
            foo2(i);
        end = clock();
        cout << t << "\t" << end - start << "\n";
        avg += end - start;
    }
    cout << "avg:\t" << avg / 10.0 << "\n\n";

    return 0;
}