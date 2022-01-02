#include <bits/stdc++.h>
using namespace std;

struct solve {
    int n, target, arr[5];
    solve();
    void DFS(int, int, map<int, int>);
};

int main() {
    map<int, int> num;
    solve sv;
    for (int i = 0; i < 5; i ++) {
        num.insert(pair<int, int>(i, 0));
    }
    sv.DFS(0, 0, num);
    return 0;
}

solve::solve() {
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    cin >> target;
}

void solve::DFS(int index, int sum, map<int, int> num) {
    if (index < n) {
        DFS(index + 1, sum, num);
    }
    if (sum < target && index < n) {
        num[index] ++;
        DFS(index, sum + arr[index], num);
        num[index] --;
    }
    if (index >= n && sum == target) {
        printf("(");
        for (int i = 0; i < n - 1; i ++) {
            printf("%d,", num[i]);
        }
        printf("%d)\n", num[n - 1]);
    }
}