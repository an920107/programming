#include <iostream>
#define MAX_ARR_SIZE 1000

using namespace std;

int main() {
    int n, num[MAX_ARR_SIZE], min, min_location, buffer;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        for (int first_location = 0; first_location < n; first_location++) {
            min = num[first_location];
            min_location = first_location;
            for (int i = first_location + 1; i < n; i++) {
                if (num[i] < min)  {
                    min = num[i];
                    min_location = i;
                }
            }
            buffer = num[first_location];
            num[first_location] = min;
            num[min_location] = buffer;
        }
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
