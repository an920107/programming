#include <iostream>

using namespace std;

int CountSummation(int, int);
int CountResult(int, int, int, int);
int food[500][500], sum[501][501];

int main() {
    int n, m, row_1, row_2, col_1, col_2;
    for (int i = 0; i < 501; i++) {
        sum[0][i] = 0;
        sum[i][0] = 0;
    }
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++) {
                scanf("%d", &food[i][j]);
                sum[i + 1][j + 1] = CountSummation(i + 1, j + 1);
            }
        for (int i = 0; i < m; i ++) {
            scanf("%d %d %d %d", &row_1, &col_1, &row_2, &col_2);
            printf("%d\n", CountResult(row_1, col_1, row_2, col_2));
        }
    }
    return 0;
}

int CountSummation(int row, int col) {
    return sum[row - 1][col] + sum[row][col - 1] +
        food[row - 1][col - 1] - sum[row - 1][col - 1];
}

int CountResult(int row_1, int col_1, int row_2, int col_2) {
    return sum[row_2][col_2] + sum[row_1 - 1][col_1 - 1] -
        sum[row_2][col_1 - 1] - sum[row_1 - 1][col_2];
}