#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {31, 17, 33, 22, 16};
    int *ptr = arr;
    for (int i = 0; i < 5; i ++) {
        *(ptr + i) += 10;
    }
    for (int i = 0; i < 5; i ++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    system("pause");
    return 0;
}
