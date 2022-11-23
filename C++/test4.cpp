#include <bits/stdc++.h>
using namespace std;

class BigNumber {
private:
    string num;

public:
    BigNumber() : num("0") {}
    BigNumber(string &_num) : num(_num) {}

    inline string &toString() { return num; }

    inline int length() { return num.length(); }

    BigNumber square() {
        vector<int> vec(num.length() * 2);
        for (int i = num.length() - 1; i >= 0; i --)
            for (int j = num.length() - 1; j >= 0; j --)
                vec[i + j + 1] += (num[i] - '0') * (num[j] - '0');
        for (int i = vec.size() - 1; i > 0; i --) {
            vec[i - 1] += vec[i] / 10;
            vec[i] %= 10;
        }
        string str = "";
        for (int i = 0, firstZero = true; i < vec.size(); i ++) {
            if (firstZero && vec[i] == 0) continue;
            firstZero = false;
            str += (char)(vec[i] + '0');
        }
        return BigNumber(str);
    }

    friend BigNumber operator+(BigNumber &x, BigNumber &y) {
        int maxLen = max(x.num.length(), y.num.length());
        int xNum, yNum;
        vector<int> vec(maxLen + 1);
        for (int i = 0; i < maxLen; i ++) {
            if (x.num.length() <= i)
                xNum = 0;
            else xNum = x.num[x.num.length() - i - 1] - '0';
            if (y.num.length() <= i)
                yNum = 0;
            else yNum = y.num[y.num.length() - i - 1] - '0';
            vec[vec.size() - i - 1] = xNum + yNum;
        }
        for (int i = vec.size() - 1; i > 0; i --) {
            vec[i - 1] += vec[i] / 10;
            vec[i] %= 10;
        }
        string str = "";
        for (int i = 0, firstZero = true; i < vec.size(); i ++) {
            if (firstZero && vec[i] == 0) continue;
            firstZero = false;
            str += (char)(vec[i] + '0');
        }
        return BigNumber(str);
    }
    
    void operator/=(int n) {
        for (int i = 0; i < num.length() - 1; i ++) {
            int k = num[i] - '0';
            num[i + 1] += k % n * 10;
            num[i] = k / n + '0';
        }
        num[num.length() - 1] = (num[num.length() - 1] - '0') / n + '0';
        if (num[0] == '0') num = num.substr(1, num.length() - 1);
    }

    friend bool operator==(BigNumber &x, BigNumber &y) {
        return x.num == y.num;
    }

    friend bool operator<(BigNumber &x, BigNumber &y) {
        if (x.num.length() != y.num.length())
            return x.num.length() < y.num.length();
        for (int i = 0; i < x.num.length(); i ++)
            if (x.num[i] != y.num[i])
                return x.num[i] < y.num[i];
        return false;
    }
};

void solve(string &str) {
    if (str == "1") {
        cout << "1\n\n";
        return;
    }
    BigNumber ori(str);
    BigNumber num(str);
    BigNumber lower;
    BigNumber upper(str);

    while (upper.length() * 2 - 1 > ori.length()) {
        upper /= 8;
    }

    while (true) {
        num = upper + lower;
        num /= 2;

        BigNumber numSquare = num.square();
        if (numSquare == ori)
            break;
        else if (numSquare < ori)
            lower = num;
        else
            upper = num;
    }
    cout << num.toString() << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string str;
    cin >> t;
    while (t --) {
        cin >> str;
        solve(str);
    }
    return 0;
}