#include <bits/stdc++.h>

using namespace std;

void PrintLand(int);
char land[500][500];

int main() {
    int n, m, row_1, row_2, col_1, col_2;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                land[i][j] = ' ';
        scanf("%d %d", &row_1, &col_1);
        land[row_1 - 1][col_1 - 1] = '*';
        for (; m > 1; m --) {
            scanf("%d %d", &row_2, &col_2);
            for (int i = min<int>(row_1, row_2) - 1; i < max<int>(row_1, row_2); i ++)
                for (int j = min<int>(col_1, col_2) - 1; j < max<int>(col_1, col_2); j ++)
                    land[i][j] = '*';
            row_1 = row_2;
            col_1 = col_2;
        }
        PrintLand(n);
    }
    return 0;
}

void PrintLand(int n) {
    for (int i = 0; i <= n + 1; i ++)
        printf("-");
    printf("\n");
    for (int i = 0; i < n; i ++) {
        printf("|");
        for (int j = 0; j < n; j ++)
            printf("%c", land[i][j]);
        printf("|\n");
    }
    for (int i = 0; i <= n + 1; i ++)
        printf("-");
    printf("\n");
}