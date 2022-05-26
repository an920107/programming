#include <bits/stdc++.h>
using namespace std;

int main() {
    int *ptr;
    for (int i = 0; i < 10; i ++) {
        *(ptr) = i;
    }

    for (int i = 0; i < 10; i ++) {
        cout << ptr[i];
    }
}