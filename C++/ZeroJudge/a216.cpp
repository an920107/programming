#include <iostream>

using namespace std;

long f(long);
long g(long);

int main() {
    int n;
    while (cin >> n) {
        cout << f(n) << " " << g(n) << "\n";
    }
    return 0;
}

long f(long n) {
    if (n == 1) return 1;
    else return n + f(n - 1);
}

long g(long n) {
    if (n == 1) return 1;
    else return f(n) + g(n - 1);
}
