#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, l, r, input, output;
    vector<int> food, sum;
    while (cin >> n >> m) {
        food.clear();
        sum.clear();
        sum.push_back(0);
        for (int i = 0; i < n; i ++) {
            cin >> input;
            food.push_back(input);
            sum.push_back(sum[i] + input);
        }
        for (int i = 0; i < m; i ++) {
            cin >> l >> r;
            output = sum[r] - sum[l - 1];
            printf("%d\n", output);
        }
    }
    return 0;
}
