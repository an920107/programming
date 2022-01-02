#include <iostream>

using namespace std;

int main() {
    int n, input, result[3] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        result[input % 3]++;
    }
    for (int i = 0; i < 3; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
