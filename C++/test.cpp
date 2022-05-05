#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 3, y = 0;
    int *ptr = &x;
    printf("[%x] %x -> %d\n", &ptr, ptr, *ptr);
    ptr = &y;
    printf("[%x] %x -> %d\n", &ptr, ptr, *ptr);
    return 0;
}