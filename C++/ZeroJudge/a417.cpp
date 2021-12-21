#include <iostream>

using namespace std;

int main() {
    int output[100][100], t, length, clockwise, count;
    scanf("%d", &t);
    for (; t > 0; t--) {
        cin >> length >> clockwise;
        count = 1;

        for (int layer = 0; layer < (length + 1) / 2; layer++) {
            for (int i = layer, j = layer; j < length - layer; j++) {
                output[i][j] = count;
                count++;
            }
            for (int i = layer + 1, j = length - layer - 1; i < length - layer; i++) {
                output[i][j] = count;
                count++;
            }
            for (int i = length - layer - 1, j = length - layer - 2; j >= layer; j--) {
                output[i][j] = count;
                count++;
            }
            for (int i = length - layer - 2, j = layer; i > layer; i--) {
                output[i][j] = count;
                count++;
            }
        }
        
        if (clockwise == 1) { // 順時針
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    printf("%5d", output[i][j]);
                }
                cout << "\n";
            }
        }
        else { // 逆時針
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    printf("%5d", output[j][i]);
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
