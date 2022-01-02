#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, psw[4], psw_copy[4], guess[4], a_count, b_count;
    while (cin >> psw[0] >> psw[1] >> psw[2] >> psw[3]) {
        // for (int i = 0; i < 4; i++) {
        //     cin >> psw[i];
        // }
        for (cin >> n; n > 0; n--) {
            a_count = 0;
            b_count = 0;
            for (int i = 0; i < 4; i++) {
                psw_copy[i] = psw[i];
            }
            for (int guess_loc = 0; guess_loc < 4; guess_loc++) {
                cin >> guess[guess_loc];
                if (guess[guess_loc] == psw_copy[guess_loc]) {
                    a_count++;
                    guess[guess_loc] = -1;
                    psw_copy[guess_loc] = -1;
                }
            }
            for (int guess_loc = 0; guess_loc < 4; guess_loc++) {
                for (int psw_loc = 0; psw_loc < 4; psw_loc++) {
                    if (guess[guess_loc] < 0 || psw_copy[psw_loc] < 0) continue;
                    else if (guess[guess_loc] == psw_copy[psw_loc]) {
                        b_count++;
                        guess[guess_loc] = -1;
                        psw_copy[psw_loc] = -1;
                    }
                }
            }
            cout << a_count << "A" << b_count << "B\n";
        }
    }
    return 0;
}
