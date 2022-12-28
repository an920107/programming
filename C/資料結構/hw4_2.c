#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void deepCopy(int* start, int* dest, int size) {
    int i;
    for (i = 0; i < size; i ++)
        dest[i] = start[i];
}

void swap(int* xPtr, int* yPtr) {
    int tmp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = tmp;
}

void bubbleSort(int arr[MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i ++)
        for (j = i; j < size; j ++)
            if (arr[i] > arr[j])
                swap(arr + i, arr + j);
}

void quickSort(int arr[MAX_SIZE], int left, int right) {
    if (left > right) return;
    int lIndex = left, rIndex = right, pivot = arr[left];
    while (lIndex != rIndex) {
        while (pivot < arr[lIndex] && lIndex < rIndex)
            lIndex ++;
        while (pivot >= arr[rIndex] && lIndex < rIndex)
            rIndex --;
        if (lIndex < rIndex)
            swap(arr + lIndex, arr + rIndex);
    }
    quickSort(arr, left, rIndex - 1);
    quickSort(arr, lIndex + 1, right);
}

int main() {
    int n, i;
    int nums[MAX_SIZE], numsCopy[MAX_SIZE], result[MAX_SIZE];
    clock_t bubbleSortClocks, quickSortClocks;
    while (scanf("%d", &n) != EOF && n != -1) {
        for (i = 0; i < n; i ++)
            scanf("%d", nums + i);
        deepCopy(nums, numsCopy, n);

        bubbleSortClocks = clock();
        bubbleSort(nums, n);
        bubbleSortClocks = clock() - bubbleSortClocks;

        quickSortClocks = clock();
        quickSort(numsCopy, 0, n);
        quickSortClocks = clock() - quickSortClocks;

        for (i = 0; i < n; i ++)
            printf("%d ", nums[i]);
        putchar('\n');
        printf("bubble sort: %.4lf sec\n", (double)bubbleSortClocks / CLOCKS_PER_SEC);
        printf("quick sort: %.4lf sec\n", (double)quickSortClocks / CLOCKS_PER_SEC);
    }
    return 0;
}