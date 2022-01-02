#include <bits/stdc++.h>

using namespace std;

void DFS(int, int, int, char[]);

int main() {
    char str[27];
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(str, 0, 27);
        DFS(0, 0, n, str);
        printf("\n");
    }

    return 0;
}

void DFS(int l_count, int r_count, int n, char str[28]) {
    if (l_count < n) {
        str[l_count + r_count] = '(';
        DFS(l_count + 1, r_count, n, str);
    }
    if (r_count < n && l_count > r_count) {
        str[l_count + r_count] = ')';
        DFS(l_count, r_count + 1, n, str);
    }
    if (r_count == n) {
        printf("%s\n", str);
    }
}
