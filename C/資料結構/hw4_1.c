#include <stdio.h>
#include <stdlib.h>

int kruskal() {
    
}

int main() {
    int n, i;
    int* inputPtr;
    while (scanf("%d", &n) != EOF && n != -1) {
        int *adjacencyMatrix = (int*)malloc(n * n * sizeof(int));
        for (i = n * n, inputPtr = adjacencyMatrix; i > 0; i --)
            scanf("%d", inputPtr ++);
        // printf("Prim minimum cost: %d\n");
        // printf("Kruskal minimum cost: %d\n");
        free(adjacencyMatrix);
    }
    return 0;
}