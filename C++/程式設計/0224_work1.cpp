#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    const double aim = 5.0;
    int day = 0;
    double len = 3000;
    while (len >= aim) {
        len /= 2;
        day ++;
    }
    cout << day << "\n";
    system("pause");
    return 0;
}
