#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool change = false;
    int n, int_buffer, dig[1000];
    string input, str_buffer, str[1000];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> input;
            str[i] = input;
            if (input[0] != '-')
                dig[i] = input.length();
            else
                dig[i] = -1 * (input.length() - 1);
        }
        // 依位數多寡由小到大選擇排序
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - j - 1; i++) {
                if (dig[i] > dig[i + 1]) {
                    int_buffer = dig[i];
                    dig[i] = dig[i + 1];
                    dig[i + 1] = int_buffer;
                    str_buffer = str[i];
                    str[i] = str[i + 1];
                    str[i + 1] = str_buffer;
                }
            }
        }
        // 同位數排序
        for (int end = 0, same = 0, begin = 0; end < n - 1; end++) {
            if (dig[end] == dig[end + 1]) same++;
            if (same > 0 && (dig[end] != dig[end + 1]) || end == n - 2) {
                if (end == n - 2) end++;
                begin = end - same;
                // 選擇排序
                for (int j = begin; j <= end; j++) {
                    for (int i = begin; i < end - j; i++) {
                        // 比大小
                        for (int d = 0; d < str[i].length(); d++) {
                            if (str[i][d] > str[i + 1][d]) {
                                change = true;
                                break;
                            }
                        }
                        if (dig[i] < 0) change = !change;
                        // 交換
                        if (change) {
                            str_buffer = str[i];
                            str[i] = str[i + 1];
                            str[i + 1] = str_buffer;
                            change = false;
                        }
                    }
                }
                same = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << str[i] << '\n';
        }
    }
    return 0;
}
