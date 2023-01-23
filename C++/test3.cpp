#include <bits/stdc++.h>
using namespace std;

int main() {
    char tmp[1000];
    FILE *file = fopen("哈.txt", "r");
    while (fscanf(file, "%s", tmp) != EOF) {
        cout << tmp << '\n';
    }
    return 0;
}