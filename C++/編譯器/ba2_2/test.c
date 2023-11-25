#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tmp[10];
    strcpy(tmp, "123123\n\0");
    printf(tmp);
    return 0;
}