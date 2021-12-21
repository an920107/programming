#include <iostream>

using namespace std;

int main() {
    int n, num[1000], min_d, max_t, min_lcation, buffer;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        for (int first_location = 0; first_location < n; first_location++) {
            min_d = num[first_location] % 10;
            max_t = num[first_location] / 10;
            min_lcation = first_location;
            for (int i = first_location + 1; i < n; i++) {
                if (min_d > num[i] % 10 || (min_d == num[i] % 10 && max_t < num[i] / 10)) {
                    min_d = num[i] % 10;
                    max_t = num[i] / 10;
                    min_lcation = i;
                }                
            }
            buffer = num[first_location];
            num[first_location] = num[min_lcation];
            num[min_lcation] = buffer;
        }
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
