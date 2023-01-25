#include <bits/stdc++.h>
using namespace std;

void solve(int n) {

    set<int> children;
    // 初始化 set
    // n * log(n)
    for (int i = 1; i <= n; i ++)
        children.insert(i);
    
    auto iter = children.begin();
    // n * log(n)
    while (!children.empty()) { // n
        if (++ iter == children.end())
            iter = children.begin();
        // 輸出被刪掉的人
        cout << *iter << ' ';
        // erase 會回傳原本 iter 的下個位置
        iter = children.erase(iter); // log(n)
        if (iter == children.end())
            iter = children.begin();
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}