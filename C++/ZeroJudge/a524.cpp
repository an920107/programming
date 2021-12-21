#include <iostream>

#define MAX_LENGTH 8

using namespace std;

int main() {
    int n, output[MAX_LENGTH], copy[MAX_LENGTH], partition_number, change_number, buffer;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            output[i] = n - i;
            printf("%d", output[i]);
        }
        printf("\n");
        partition_number = n - 2;
        while (partition_number >= 0) {
            if (output[partition_number] > output[partition_number + 1]) {
                for (change_number = n - 1; change_number > partition_number; change_number--) {
                    if (output[change_number] < output[partition_number]) {
                        buffer = output[change_number];
                        output[change_number] = output[partition_number];
                        output[partition_number] = buffer;
                        for (int i = 0; i < n; i++) {
                            copy[i] = output[i];
                        }
                        for (int begin = partition_number + 1, i = 0; begin + i < n; i++) {
                            output[begin + i] = copy[n - i - 1];
                        }
                        for (int i = 0; i < n; i++) {
                            printf("%d", output[i]);
                        }
                        printf("\n");
                        partition_number = n - 2;
                        break;
                    }
                }
            }
            else partition_number--;
        }
    }
    return 0;
}
