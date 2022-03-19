#include <bits/stdc++.h>
using namespace std;

#define ROW 2
#define COL 4

double average(int arr[ROW][COL]) {
    double sum = 0;
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL; j ++) {
            sum += arr[i][j];
        }
    }
    return sum / ROW / COL;
}

int main() {
    int arr[ROW][COL]{{6, 7, 8, 9}, {10, 11, 12, 13}};
    printf("Average: %lf\n", average(arr));

    system("pause");
    return 0;
}
