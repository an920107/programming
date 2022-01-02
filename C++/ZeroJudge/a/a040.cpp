#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int pow(int, int);

int main() {
    int n = 0, m = 0, sum;
    string str;
    stringstream ss;
    bool flag = false;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        for (int pwr = 1; pwr < 50; pwr++) {
            ss.clear();
            ss << i;
            ss >> str;
            sum = 0;
            for (int digit = 0; digit < str.length(); digit++) {
                sum += pow(str[digit] - 48, pwr);
            }
            if (sum > i) break;
            else if (sum == i) {
                flag = true;
                cout << sum << ' ';
                break;
            }
        }
    }
    if (!flag) cout << "none";
    return 0;
}

int pow(int a, int x) {
    int output = 1;
    for (int i = 0; i < x; i++) {
        output *= a;
    }
    return output;
}