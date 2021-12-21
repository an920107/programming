#include <iostream>

using namespace std;

int main() {
    int y;
    while (cin >> y) {
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0) {
                    cout << "閏年" << '\n';
                }
                else cout << "平年" << '\n';
            }
            else cout << "閏年" << '\n';
        }
        else cout << "平年" << '\n';
    }
    return 0;
}
