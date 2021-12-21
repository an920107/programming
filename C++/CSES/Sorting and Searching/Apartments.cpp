#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 200000

int main() {
    int n, m, k, sum = 0;
    int targets[MAX_SIZE], capacity[MAX_SIZE];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) {
        cin >> targets[i];
    }
    for (int i = 0; i < m; i ++) {
        cin >> capacity[i];
    }
    sort(targets, targets + n);
    sort(capacity, capacity + m);
    for (int i = 0, j = 0; i < n; ) {
        if (targets[i] < capacity[j] - k) {
            i ++;
        }
        else if (targets[i] >= capacity[j] - k && targets[i] <= capacity[j] + k) {
            sum ++;
            i ++;
            j ++;
        }
        else {
            j ++;
        }
    }
    cout << sum << "\n";
    return 0;
}
