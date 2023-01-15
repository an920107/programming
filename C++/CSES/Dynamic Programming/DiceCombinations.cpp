#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007 // 1E9 + 7

class Solve {
private:

    int n, result;
    vector<int> count;

    int run(int leftPoints) {
        // 還沒處理過
        if (count[leftPoints] == 0) {
            // 點數一到六，依序嘗試移出該點數數量
            for (int toRemove = 1; toRemove <= 6; toRemove ++) {
                // 剩餘的點數不小於要移除的
                if (leftPoints - toRemove >= 0) {
                    count[leftPoints] += run(leftPoints - toRemove);
                    count[leftPoints] %= MOD;
                }
            }
        }
        return count[leftPoints];
    }

public:

    Solve(int _n) : n(_n), count(_n + 1, 0) {
        if (n == 0)
            result = 1;
        else {
            count[0] = 1;
            result = run(n);
        }
    }

    inline int getResult() {
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    Solve solve(n);
    cout << solve.getResult() << '\n';
    return 0;
}