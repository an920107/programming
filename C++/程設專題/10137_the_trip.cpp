#include <bits/stdc++.h>
using namespace std;

int solve(int count, vector<int> values) {
    int sum = 0;
    for (auto x : values)
        sum += x;
    int avg = sum / count, remain = sum % count;
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());
    int result = 0;
    for (auto x : values) {
        if (remain) {
            result += abs(x - avg - 1);
            remain--;
        }
        else {
            result += abs(x - avg);
        }
    }
    result /= 2;
    return result;
}

int main() {
    int count;
    while (cin >> count) {
        if (count == 0)
            break;
        
        vector<int> values(count);
        for (int i = 0; i < count; i++) {
            int dollars, cents;
            scanf("%d.%d", &dollars, &cents);
            values[i] = dollars * 100 + cents;
        }
        int result = solve(count, values);
        printf("$%.2f\n", result / 100.0);
    }

    return 0;
}