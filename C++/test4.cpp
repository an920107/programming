#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr1[] = {10, 5, 4, -6, 2, 11, 12};
    int arr2[] = {10, 5, 3,  1, 4,  2, -6};
    int result;

    asm("\
        mov %[arr1], %%rsi\n\
        mov %[arr2], %%rdi\n\
        mov %[size], %%rcx\n\
        mov $0x0, %%rax\n\
    L1:\n\
        mov (%%rsi), %%ebx\n\
        cmp (%%rdi), %%ebx\n\
        jnz L2\n\
        inc %%rax\n\
    L2:\n\
        add $0x4, %%rsi\n\
        add $0x4, %%rdi\n\
        loop L1\n\
        mov %%eax, %[result]\n\
    "
    :[result]"=r"(result)
    :[arr1]"r"(arr1), [arr2]"r"(arr2), [size]"r"(sizeof(arr1) / sizeof(int))
    );
    printf("%+d\n", result);

    asm("\
        mov %[arr1], %%rsi\n\
        mov %[arr2], %%rdi\n\
        mov %[size], %%rcx\n\
        push %%rcx\n\
        mov $0x0, %%rax\n\
    L5:\n\
        push %%rcx\n\
        push %%rdi\n\
        mov 0x10(%%rsp), %%rcx\n\
    L3:\n\
        mov (%%rsi), %%ebx\n\
        cmp (%%rdi), %%ebx\n\
        jnz L4\n\
        inc %%rax\n\
    L4:\n\
        add $0x4, %%rdi\n\
        loop L3\n\
        add $0x4, %%rsi\n\
        pop %%rdi\n\
        pop %%rcx\n\
        loop L5\n\
        mov %%eax, %[result]\n\
    "
    :[result]"=r"(result)
    :[arr1]"r"(arr1), [arr2]"r"(arr2), [size]"r"(sizeof(arr1) / sizeof(int))
    );
    printf("%+d\n", result);

    return 0;
}