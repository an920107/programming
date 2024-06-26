#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF __INT32_MAX__

typedef struct {
    int** matrix;
    int size;
} AdjacencyMatrix;

typedef struct {
    int begin, end, weigh;
} Edge;

int edgeCmp(const void* _x, const void* _y) {
    Edge* x = (Edge*)_x;
    Edge* y = (Edge*)_y;
    if (x->weigh < y->weigh) return -1;
    if (x->weigh > y->weigh) return 1;
    return 0;
}

void** malloc2DArray(size_t size, int row, int col) {
    int i;
    void** arr = (void**)malloc(row * sizeof(void*));
    for (i = 0; i < row; i ++)
        arr[i] = (void*)malloc(col * size);
    return arr;
}

int findRoot(const int* set, int i) {
    while (set[i] > -1)
        i = set[i];
    return i;
}

bool isSameSet(const int* set, int x, int y) {
    return findRoot(set, x) == findRoot(set, y);
}

void unionSet(int* set, int x, int y) {
    int xRoot = findRoot(set, x);
    int yRoot = findRoot(set, y);
    if (set[xRoot] <= set[yRoot]) {
        set[xRoot] += set[yRoot];
        set[yRoot] = xRoot;
    }
    else {
        set[yRoot] += set[xRoot];
        set[xRoot] = yRoot;
    }
}

/**
 * main functoins
*/

int prim(const AdjacencyMatrix* adjMatrix) {
    int result = 0, count = adjMatrix->size - 1 , i, minKey, minKeyPoint;
    bool* visited = (bool*)malloc(adjMatrix->size * sizeof(bool));
    memset(visited, false, adjMatrix->size * sizeof(bool));
    int* parent = (int*)malloc(adjMatrix->size * sizeof(int));
    memset(parent, -1, adjMatrix->size * sizeof(bool));
    int* key = (int*)malloc(adjMatrix->size * sizeof(int));
    for (i = 0; i < adjMatrix->size; i ++)
        key[i] = INF;
    key[0] = 0;
    while (count --) {
        for (i = 0, minKey = INF; i < adjMatrix->size; i ++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                minKeyPoint = i;
            }
        }
        visited[minKeyPoint] = true;
        for (i = 0; i < adjMatrix->size; i ++) {
            int weigh = adjMatrix->matrix[minKeyPoint][i];
            if (weigh == INF || visited[i])
                continue;
            if (weigh < key[i]) {
                parent[i] = minKeyPoint;
                key[i] = weigh;
            }
        }
    }
    for (i = 0; i < adjMatrix->size; i ++)
        result += key[i];
    free(visited);
    free(parent);
    free(key);
    return result;
}

int kruskal(const AdjacencyMatrix* adjMatrix) {
    int result = 0, count = adjMatrix->size - 1, i, j, index = 0;
    int* subset = (int*)malloc(count * (count + 1) / 2 * sizeof(int));
    memset(subset, -1, adjMatrix->size * sizeof(int));
    Edge* edges =(Edge*)malloc(count * (count + 1) / 2 * sizeof(Edge));
    for (i = 0; i < adjMatrix->size; i ++) {
        for (j = i + 1; j < adjMatrix->size; j ++) {
            edges[index].begin = i;
            edges[index].end = j;
            edges[index ++].weigh = adjMatrix->matrix[i][j];
        }
    }
    qsort(edges, count * (count + 1) / 2, sizeof(Edge), edgeCmp);
    for (i = 0, j = 0; i < count * (count + 1) / 2 && j < count; i ++) {
        if (isSameSet(subset, edges[i].begin, edges[i].end))
            continue;
        unionSet(subset, edges[i].begin, edges[i].end);
        result += edges[i].weigh;
        j ++;
    }
    free(subset);
    return result;
}

int main() {
    AdjacencyMatrix* adjMatrix;
    int n, i, j, tmp;
    while (scanf("%d", &n) != EOF && n != -1) {
        adjMatrix->size = n;
        adjMatrix->matrix = (int**)malloc2DArray(sizeof(int), n, n);
        for (i = 0; i < adjMatrix->size; i ++) {
            for (j = 0; j < adjMatrix->size; j ++) {
                scanf("%d", &tmp);
                adjMatrix->matrix[i][j] = tmp == 0 ? INF : tmp;
            }
        }
        printf("Prim minimum cost: %d\n", prim(adjMatrix));
        printf("Kruskal minimum cost: %d\n", kruskal(adjMatrix));
        free(adjMatrix->matrix);
    }
    return 0;
}