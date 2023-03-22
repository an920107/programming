#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

class BigNumber {
private:

    vector<__int8_t> vec;

    void tidyup() {
        vec.emplace_back(0);
        for (int i = 0; i < vec.size() - 1; i ++)
            if (vec[i] >= 10) {
                vec[i + 1] += vec[i] / 10;
                vec[i] %= 10;
            }
        if (vec.back() == 0)
            vec.pop_back();
    }

public:

    BigNumber() : vec({0}) {}

    BigNumber(const string &str) : vec(str.length()) {
        for (int i = 0; i < str.length(); i ++)
            vec[i] = str[str.length() - i - 1] - '0';
    }

    inline size_t dig() { return vec.size(); }

    string parse_to_string() {
        string str;
        for (int i = vec.size() - 1; i >= 0; i --)
            str.append(to_string(vec[i]));
        return str;
    }

    inline int parse_to_llong() {
        return stoll(this->parse_to_string());
    }

    BigNumber mul10(int n) {
        BigNumber result;
        result.vec = vec;
        vector<__int8_t> to_insert(n);
        result.vec.insert(result.vec.begin(), to_insert.begin(), to_insert.end());
        return result;
    }

    BigNumber operator+(BigNumber &num) {
        BigNumber result;
        int max_dig = max(this->dig(), num.dig());
        result.vec = vector<__int8_t>(max_dig);
        for (int i = 0; i < max_dig; i ++) {
            if (i < this->vec.size())
                result.vec[i] += this->vec[i];
            if (i < num.vec.size())
                result.vec[i] += num.vec[i];
        }
        result.tidyup();
        return result;
    }

    BigNumber operator-(BigNumber &num) {
        BigNumber result;
        result.vec = this->vec;
        for (int i = 0; i < result.vec.size(); i ++) {
            int to_sub = 0;
            if (i < num.vec.size())
                to_sub = num.vec[i];
            if (result.vec[i] < to_sub) {
                result.vec[i + 1] --;
                result.vec[i] += 10;
            }
            result.vec[i] -= to_sub;
        }
        while (result.dig() > 1 && result.vec.back() == 0)
            result.vec.pop_back();
        return result;
    }

    BigNumber operator*(BigNumber &num) {
        if (this->dig() <= 9 || num.dig() <= 9)
            return BigNumber(to_string(this->parse_to_llong() * num.parse_to_llong()));

        const int max_dig_2 = max(this->dig(), num.dig()) / 2;
        BigNumber x_low, x_high, y_low, y_high;
        x_low.vec = vector<__int8_t>(this->vec.begin(), this->vec.begin() + max_dig_2);
        x_high.vec = vector<__int8_t>(this->vec.begin() + max_dig_2, this->vec.end());
        y_low.vec = vector<__int8_t>(num.vec.begin(), num.vec.begin() + max_dig_2);
        y_high.vec = vector<__int8_t>(num.vec.begin() + max_dig_2, num.vec.end());
        BigNumber z0 = x_low * y_low;
        BigNumber z1_x = x_low + x_high;
        BigNumber z1_y = y_low + y_high;
        BigNumber z1 = z1_x * z1_y;
        BigNumber z2 = x_high * y_high;

        z1 = (z1 - z2 - z0).mul10(max_dig_2);
        z2 = z2.mul10(max_dig_2 * 2);

        return z0 + z1 + z2;
    }

    friend istream& operator>>(istream &is, BigNumber &num) {
        string str;
        is >> str;
        num = BigNumber(str);
        return is;
    }

    friend ostream& operator<<(ostream &os, BigNumber &num) {
        for (int i = num.vec.size() - 1; i >= 0; i --)
            os << int(num.vec[i]);
        return os;
    }
};

int main() {

    BigNumber x, y, z;
    cin >> x >> y;
    clock_t start = clock();
    for (int i = 0; i < 1; i ++)
        z = x * y;
    clock_t end = clock();
    cout << z << '\n';
    cout << (long long)(double(end - start) / CLOCKS_PER_SEC * 1E9 / 1) << '\n';

    return 0;
}