#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIG 110

char* mul(const char* digits) {

    int i;
    static char result[MAX_DIG];
    memset(result, 0, MAX_DIG);
    for (i = strlen(digits) - 1; i >= 0; i --) {
        // 多留最高位的進位空間，result 比 digits 多退一位
        result[i + 1] += (digits[i] - '0') * 2;
        result[i] += result[i + 1] >= 10;
        result[i + 1] %= 10;
        result[i + 1] += '0';
    }
    result[0] += '0';

    // 若最高位為 0，回傳第 1 位
    return (result[0] == '0') ? (result + 1) : result;
}

char* div(const char* digits) {
    
    int i, dividend, remain = 0;
    static char result[MAX_DIG];
    memset(result, 0, MAX_DIG);
    for (i = 0; i < strlen(digits); i ++) {
        dividend = remain * 10 + (digits[i] - '0');
        result[i] = dividend / 2 + '0';
        remain = dividend % 2;
    }

    // 若最高位為 0，回傳第 1 位
    return (result[0] == '0') ? (result + 1) : result;
}

int main() {
    
    char num_digits[MAX_DIG];
    while (scanf("%s", num_digits) != EOF) {
        printf("%s\n", mul(num_digits));
        printf("%s\n", div(num_digits));
        printf("\n");
    }

    return 0;
}