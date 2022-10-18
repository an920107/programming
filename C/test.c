#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -9288, *nPtr = &n;
    float f = 1, *fPtr = &f;
    printf("%d\n", *fPtr);
    printf("%f\n", *nPtr);
    return 0;
}