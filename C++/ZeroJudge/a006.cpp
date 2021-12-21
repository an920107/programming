#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d < 0)
        cout << "No real root" << '\n';
    else if (d == 0)
        cout << "Two same roots x=" << (-b) / 2 / a;
    else {
        d = sqrt(d);
        cout << "Two different roots x1=" << (-b + d) / 2 / a
            << " , x2=" << (-b - d) / 2 / a << '\n';
    }
    return 0;
}
