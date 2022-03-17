#include <bits/stdc++.h>
using namespace std;

#define ROW 2
#define COL 4

void add(int arrA[ROW][COL], int arrB[ROW][COL], int arrC[ROW][COL]) {
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL; j ++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
}

char* printArr(int arr[ROW][COL]) {
    string str;
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL; j ++) {
            str += to_string(arr[i][j]);
            str += " ";
        }
        str += "\n";
    }
    char *cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}

int main() {
    int arrA[ROW][COL]{{6, 7, 8, 9}, {10, 11, 12, 13}};
    int arrB[ROW][COL]{{8, 9, 10, 11}, {12, 13, 14, 15}};
    int arrC[ROW][COL];

    add(arrA, arrB, arrC);

    printf("A:\n%s\n\nB:\n%s\n\nC:\n%s\n", printArr(arrA), printArr(arrB), printArr(arrC));

    system("pause");
    return 0;
}