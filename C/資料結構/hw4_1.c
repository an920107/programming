#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF __INT16_MAX__

void malloc2DArray(int*** arr, int row, int col) {
    int i, j;
    *arr = (int**)malloc(row * sizeof(int*));
    for (i = 0; i < row; i ++)
        (*arr)[i] = (int*)malloc(col * sizeof(int));
}

int main() {
    int n, i, j, tmp;
    int** matrix;
    while (scanf("%d", &n) != EOF && n != -1) {
        malloc2DArray(&matrix, n, n);
        for (i = 0; i < n; i ++) {
            for (j = 0; j < n; j ++) {
                scanf("%d", &tmp);
                matrix[i][j] = tmp == 0 ? INF : tmp;
            }
        }
        free(matrix);
    }
    return 0;
}