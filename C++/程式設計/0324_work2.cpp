#include <bits/stdc++.h>
using namespace std;

void square(int *ptr) {
    for (int i = 0; i < 5; i ++) {
        *(ptr + i) *= *(ptr + i);
    }
}

int main() {
    int arr[] = {31, 17, 33, 22, 16};
    square(arr);
    for (int i = 0; i < 5; i ++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    system("pause");
    return 0;
}