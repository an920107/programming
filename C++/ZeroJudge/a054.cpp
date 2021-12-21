#include <iostream>

using namespace std;

int main() {
    const int code[26] = {1, 10, 19, 28, 37, 46, 55, 64, 39, 73, 82, 2, 11, 20, 48, 29, 38, 47, 56, 65, 74, 83, 21, 3, 12, 30};
    int num[9], sum = 0, check;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        num[i] = input[i] - 48;
    }
    for (int i = 0; i < 8; i++) {
        sum += num[i] * (8 - i);
    }
    for (int i = 0; i < 26; i++) {
        check = 10 - (code[i] + sum) % 10;
        if (check == 10) check = 0;
        if (check == num[8]) cout << char(i + 65);
    }
    return 0;
}

/*
台北市 A 10 1   彰化縣 N 22 20
台中市 B 11 10  新竹市 O 35 48
基隆市 C 12 19  雲林縣 P 23 29
台南市 D 13 28  嘉義縣 Q 24 38
高雄市 E 14 37  台南縣 R 25 47
台北縣 F 15 46  高雄縣 S 26 56
宜蘭縣 G 16 55  屏東縣 T 27 65
桃園縣 H 17 64  花蓮縣 U 28 74
嘉義市 I 34 39  台東縣 V 29 83
新竹縣 J 18 73  金門縣 W 32 21
苗栗縣 K 19 82  澎湖縣 X 30 3
台中縣 L 20 2   陽明山 Y 31 12
南投縣 M 21 11  連江縣 Z 33 30
*/