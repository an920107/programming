#include <iostream>

using namespace std;

int main() {
    string input, changed;
    int skipped, count, bad_count;
    while (cin >> input) {
        changed = input;
        skipped = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] >= 'a' && input[i] <= 'z') changed[i - skipped] = input[i];
            else if (input[i] >= 'A' && input[i] <= 'Z') changed[i - skipped] = input[i] + 32;
            else skipped++;
        }
        bad_count = 0;
        for (char letter = 'a'; letter < 'z'; letter++) {
            count = 0;
            for (int i = 0; i < input.length() - skipped; i++) {
                if (changed[i] == letter) count++;
            }
            if (count % 2 == 1) bad_count++;
        }
        if (bad_count > 1) cout << "no...\n";
        else cout << "yes !\n";
    }
    return 0;
}
