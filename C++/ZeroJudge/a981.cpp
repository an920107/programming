#include <bits/stdc++.h>
using namespace std;

struct Solve {
    int n, m, arr[40];
    void sort();
    bool isPossible();
    void DFS(int, long long, long long);
};

int main() {
    Solve sv;
    cin >> sv.n >> sv.m;
    for (int i = 0; i < sv.n; i ++) {
        cin >> sv.arr[i];
    }
    if (sv.isPossible()) {
        sv.sort();
        sv.DFS(0, 0, 0);
    }
    else cout << "-1\n";
    return 0;
}

void Solve::sort() {
    std::sort(arr, arr + n);
}

bool Solve::isPossible() {
    long long sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += arr[i];
    }
    return sum >= m;
}

void Solve::DFS(int index, long long sum, long long res) {
    if (sum > (long long)m) return;
    if (index < n) DFS(index + 1, sum + arr[index], (res + 1) << 1);
    if (index < n) DFS(index + 1, sum, res << 1);
    if (index >= n) {
        if (sum == (long long)m) {
            res >>= 1;
            for (int i = 0; i < n; i ++) {
                if (res & 1) cout << arr[i] << " ";
                res >>= 1;
            }
            cout << "\n";
        }
    }
}
