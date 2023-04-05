#include <bits/stdc++.h>
using namespace std;

int main() {

    long long t0 = 0xAAAAAAAA;
    long long t1 = 0x12345678;
    long long t2;


    t2 = t0 >> 3;
    t2 &= 0xFFEF;

    printf("%llX\n", t2);

    return 0;
}