#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int find_k(int n) {
    if (n == 0) return -1;
    const int acc = (n >= -1 ? 1 : -1);
    for (int i = 0; ; i += acc) {
        if (abs(i * 4 + 2) > abs(n)) {
            const int k_1 = i, k_2 = i - acc;
            if (abs(k_1 * 4 + 2 - n) <= abs(k_2 * 4 + 2 - n))
                return k_1;
            else return k_2;
        }
    }
}

int main() {
    int n;
    cout << "Input n: "; cin >> n;
    cout << "k = " << find_k(n) << "\n";
    system("pause");
    return 0;
}