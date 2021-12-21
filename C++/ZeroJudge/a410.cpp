#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    float a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    float delta = a1 * b2 - b1 * a2;
    float delta_x = c1 * b2 - b1 * c2;
    float delta_y = a1 * c2 - c1 * a2;
    if (delta == 0) {
        if (delta_x == 0 && delta_y == 0) cout << "Too many\n";
        else cout << "No answer\n";
    }
    else {
        cout << fixed << setprecision(2);
        cout << "x=" << round(delta_x / delta * 100) / 100 << "\n";
        cout << "y=" << round(delta_y / delta * 100) / 100 << "\n";
    }
    return 0;
}
