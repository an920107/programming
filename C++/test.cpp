#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[2][2];
    for (int i = 0; i < 4; i ++) {
        printf("%x ", *arr + i);
    }
    printf("\n");
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 2; j ++) {
            printf("%x ", &arr[i][j]);
        }
    }
    return 0;
}
