#include <bits/stdc++.h>
using namespace std;

class BigNumber : protected vector<int> {
protected:

    void tidy_up() {
        int new_size = 1;
        for (int i = this->size() - 1; i >= 0; i --)
            if ((*this)[i] != 0) {
                new_size = i + 1;
                break;
            }
        this->resize(new_size, 0);
    }

public:

    // 建構子

    BigNumber() : vector<int>(1, 0) {}

    BigNumber(size_t n, int value) : vector<int>(n, value) {}

    BigNumber(vector<int>::iterator first, vector<int>::iterator last) :
    vector<int>(first, last) {
        this->tidy_up();
    }

    BigNumber(const string &str) :
    vector<int>(str.length()) {
        for (int i = 0; i < str.length(); i ++)
            (*this)[i] = str[str.length() - i - 1] - '0';
        this->tidy_up();
    }

    BigNumber(int num) : BigNumber(to_string(num)) {}

    int parse_to_int() {
        int result = 0, exp = 1;
        for (int i = 0; i < this->size(); i ++) {
            result += (*this)[i] * exp;
            exp *= 10;
        }
        return result;
    }

    // 運算

    void operator<<=(size_t n) {
        const vector<int> to_insert(n, 0);
        this->insert(this->begin(), to_insert.begin(), to_insert.end());
    }

    BigNumber operator<<(size_t n) {
        BigNumber new_bn(*this);
        new_bn <<= n;
        return new_bn;
    }

    void operator>>=(size_t n) {
        *this = BigNumber(this->begin() + n, this->end());
    }

    BigNumber operator>>(size_t n) {
        BigNumber new_bn(*this);
        new_bn >>= n;
        return new_bn;
    }

    void operator+=(const BigNumber &bn) {
        this->resize(max(this->size(), bn.size()) + 1, 0);
        for (int i = 0; i < this->size() - 1; i ++) {
            if (i < bn.size())
                (*this)[i] += bn[i];
            (*this)[i + 1] += (*this)[i] / 10;
            (*this)[i] %= 10;
        }
        this->tidy_up();
    }

    BigNumber operator+(const BigNumber &bn) {
        BigNumber new_bn(*this);
        new_bn += bn;
        return new_bn;
    }

    void operator-=(const BigNumber &bn) {
        this->emplace_back(0);
        for (int i = 0; i < this->size() - 1; i ++) {
            if (i >= bn.size())
                continue;
            if ((*this)[i] < bn[i]) {
                (*this)[i + 1] --;
                (*this)[i] += 10;
            }
            (*this)[i] -= bn[i];
        }
        this->tidy_up();
    }

    BigNumber operator-(const BigNumber &bn) {
        BigNumber new_bn(*this);
        new_bn -= bn;
        return new_bn;
    }

    void operator*=(int n) {
        BigNumber multiplicand(*this);
        *this = BigNumber(this->size() + 1, 0);
        for (int i = 0; i < this->size() - 1; i ++) {
            (*this)[i] += multiplicand[i] * n;
            (*this)[i + 1] += (*this)[i] / 10;
            (*this)[i] %= 10;
        }
        this->tidy_up();
    }

    BigNumber operator*(int n) {
        BigNumber new_bn(*this);
        new_bn *= n;
        return new_bn;
    }

    BigNumber operator*(BigNumber &bn) {
        // if (this->size() == 1 || bn.size() == 1) {
        //     const int n = (this->size() == 1 ? this->front() : bn.front());
        //     return (this->size() == 1 ? bn : *this) * n;
        // }

        if (this->size() <= 4 && bn.size() <= 4) {
            return BigNumber(this->parse_to_int() * bn.parse_to_int());
        }
        
        const int max_dig_2 = max(this->size(), bn.size()) / 2;
        const int this_split_pos = max_dig_2 > this->size() ? this->size() : max_dig_2;
        const int bn_split_pos = max_dig_2 > bn.size() ? bn.size() : max_dig_2;
        
        BigNumber this_low(this->begin(), this->begin() + this_split_pos);
        BigNumber this_high(this->begin() + this_split_pos, this->end());
        BigNumber bn_low(bn.begin(), bn.begin() + bn_split_pos);
        BigNumber bn_high(bn.begin() + bn_split_pos, bn.end());
        
        BigNumber z0 = this_low * bn_low;
        BigNumber z1_this = this_low + this_high;
        BigNumber z1_bn = bn_low + bn_high;
        BigNumber z1 = z1_this * z1_bn;
        // BigNumber z1 = (this_low + this_high) * (bn_low + bn_high);
        BigNumber z2 = this_high * bn_high;

        return (z2 << (max_dig_2 * 2)) + ((z1 - z2 - z0) << max_dig_2) + z0;
    }



    // 輸出入

    friend istream &operator>>(istream &is, BigNumber &bn) {
        string str;
        is >> str;
        bn = BigNumber(str);
        return is;
    }

    friend ostream &operator<<(ostream &os, const BigNumber &bn) {
        for (int i = bn.size() - 1; i >= 0; i --)
            os << bn[i];
        return os;
    }

};

int main(int argc, char** argv) {

    BigNumber x, y;
    cin >> x >> y;

    if (argc <= 1)
        cout << x * y << '\n';
    else {
        for (int i = 1; i < argc; i ++) {
            if (string(argv[i]) == "-t") {
                int t = atoi(argv[++ i]);
                clock_t start = clock();
                for (int i = 0; i < t; i ++)
                    x * y;
                clock_t end = clock();
                cout << (long long)(double(end - start) / CLOCKS_PER_SEC * 1E9 / t) << '\n';
            }
        }
    }

    return 0;
}