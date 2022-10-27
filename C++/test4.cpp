#include <bits/stdc++.h>
using namespace std;

int main() {
    int **choice = (int**)malloc(6 * sizeof(int*));
    for (int i = 0; i < 6; i ++) {
        choice[i] = (int*)malloc(5 * sizeof(int));
        memset(choice[i], -1, 5 * sizeof(int));
    }
    for (int i = 0; i < 6; i ++) {
        for (int j = 0; j < 5; j ++) {
            cout << choice[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}