#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10][10], b[10][10], c[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            a[i][j] = 1;
            b[i][j] = 2;
            c[i][j] = 3;
        }
    // b[17][9] = 4;  /*location 1*/
    // b[17][16] = 5; /*location 2*/
    // b[-3][7] = 6;  /*location 3*/
    // b[-3][-6] = 7; /*location 4*/

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            int *ptr = &b[17][9];
            if (ptr == &a[i][j])
                printf("a[%d][%d]\n", i, j);
            if (ptr == &b[i][j])
                printf("b[%d][%d]\n", i, j);
            if (ptr == &c[i][j])
                printf("c[%d][%d]\n", i, j);
        }


    return 0;
}