#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10200

class BigNumber {
private:
    char arr[MAX_SIZE];
    int length;
    bool negtive;
    void push(char);
    char pop();
    void insert(char, int);
    char erase(int);
    void stripZero();
    void swap(BigNumber&, BigNumber&);
    BigNumber subArr(int, int);

public:
    BigNumber();
    BigNumber(const std::string&);
    BigNumber(const char*);
    BigNumber(const long long&);
    BigNumber operator=(std::string&);
    bool operator>(BigNumber);
    bool operator<(BigNumber);
    bool operator==(BigNumber);
    bool operator>=(BigNumber);
    bool operator<=(BigNumber);
    friend std::istream& operator>>(std::istream&, BigNumber&);
    friend std::ostream& operator<<(std::ostream&, BigNumber);
};

BigNumber::BigNumber() {
    memset(arr, 0, MAX_SIZE);
    length = 1;
    negtive = false;
}

BigNumber::BigNumber(const std::string& in) {
    memset(arr, 0, MAX_SIZE);
    length = 0;
    negtive = false;
    for (auto iter = in.rbegin(); iter != in.rend(); iter ++) {
        push(*iter - 48);
    }
    if (arr[length - 1] == '-' - 48) {
        negtive = true;
        pop();
    }
}

BigNumber::BigNumber(const char* in) {
    std::string tmp = in;
    *this = BigNumber(tmp);
}

BigNumber::BigNumber(const long long& in) {
    *this = BigNumber(std::to_string(in));
}

void BigNumber::push(char in) {
    arr[length ++] = in;
}

char BigNumber::pop() {
    char tmp = arr[-- length];
    arr[length] = 0;
    return tmp;
}

void BigNumber::swap(BigNumber& x, BigNumber& y) {
    BigNumber res = x;
    x = y, y = res;
}

void BigNumber::insert(char in, int index) {
    for (int i = length ++; i > index; i --) {
        arr[i] = arr[i - 1];
    }
    arr[index] = in;
}

char BigNumber::erase(int index) {
    char tmp = arr[index];
    length --;
    for (int i = index; i < length; i ++) {
        arr[i] = arr[i + 1];
    }
    arr[length] = 0;
    return tmp;
}

void BigNumber::stripZero() {
    for (int i = length - 1; i > 0; i --) {
        if ((*this).arr[i] != 0) return;
        pop();
    }
}

BigNumber BigNumber::subArr(int begin, int len) {
    BigNumber tmp;
    for (int i = 0; i < len; i ++) {
        tmp.push((*this).arr[begin + i]);
    }
    return tmp;
}

BigNumber BigNumber::operator=(std::string& str) {
    return BigNumber(str);
}

bool BigNumber::operator<(BigNumber obj) {
    BigNumber tmp = *this;
    if (tmp.negtive && !obj.negtive) return true;
    if (!tmp.negtive && obj.negtive) return false;
    if (tmp.negtive && obj.negtive) swap(tmp, obj);
    while (tmp.length > obj.length) obj.push(0);
    while (tmp.length < obj.length) tmp.push(0);
    for (int i = tmp.length - 1; i >= 0; i --) {
        if (tmp.arr[i] < obj.arr[i]) return true;
        if (tmp.arr[i] > obj.arr[i]) return false;
    }
    return false;
}

std::istream& operator>>(std::istream& is, BigNumber& obj) {
    std::string str;
    is >> str;
    obj = BigNumber(str);
    obj.stripZero();
    return is;
}

std::ostream& operator<<(std::ostream& os, BigNumber obj) {
    if (obj.negtive) os << "-";
    for (int i = obj.length - 1; i >= 0; i --) {
        os << char(obj.arr[i] + 48);
    }
    return os;
}

bool compare(BigNumber &x, BigNumber &y) {
    return x < y;
}

BigNumber arr[1000];

void solve(int n) {
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << "\n";
    }
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}