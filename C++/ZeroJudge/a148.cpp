#include <iostream>

using namespace std;

int main() {
    int n;
    float score, sum;
    while (cin >> n) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> score;
            sum += score;
        }
        if (sum / n > 59.0) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}
