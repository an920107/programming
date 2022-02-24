#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    const int aim = 1000;
    int sum = 0, n = 0;
    do {
        sum += (++ n);
    } while (sum < aim);
    cout << sum << "\n";
    system("pause");
    return 0;
}
