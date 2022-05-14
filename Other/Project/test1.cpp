#include <bits/stdc++.h>
using namespace std;

// bool operator<(const Data &a, const Data &b) {
//     return a.tradingPair < b.tradingPair;
// }

struct Data {
    vector<string> dat;
    bool operator<(const Data &x) const {
        return dat[6] < x.dat[6];
    }
};

void stripace(string &str) {
    if (str.empty()) return;
    int p = 0;
    while (p < str.size() and str[p] == ' ') p++;
    str = str.substr(p);
}

bool istradpair (const string &str) {
    int t = str.find('/');
    if (t == -1 or t == 0 or t == str.size() - 1) return false;
    else return isalpha(str[t-1]) and isalpha(str[t+1]);
}

map<string, string> nametime;

void newfile(const string &str, const vector<Data> &vec) {
    string tim = nametime[str];
    freopen((str + ".csv").c_str(), "a", stdout);
    cerr << str << " : " << nametime[str] << '\n';
    for (Data dat: vec) {
        if (tim >= dat.dat[6]) continue;
        // cerr << tim << "::" << dat.dat[6] << '\n';
        for (int i = 0; i < dat.dat.size(); i++)
            cout << dat.dat[i] << ",\n"[i == dat.dat.size()-1];
    }
    nametime[str] = max(nametime[str], vec.back().dat[6]);
    if (str == "Sumo") cerr << nametime[str] << '\n';
    cout.clear();
    cin.clear();
}


void savetime() {
    freopen("lasttime", "w", stdout);
    for (auto &[a, b] : nametime)
        cout << a << '\n' << b << '\n';
    cout.clear();
}

void loadtime() {
    cin.clear();
    freopen("lasttime", "r", stdin);
    string a, b;
    while (getline(cin, a) and getline(cin, b)) {
        nametime[a] = b;
    }
    cin.clear();
}

map<string, vector<Data>> mp;

int main() {
    freopen("12.csv", "r", stdin);
    freopen("out.csv", "w", stdout);
    string s;
    vector<string> vec;
    while (getline(cin, s)) stripace(s), vec.emplace_back(s);
    int cnt = 0;
    cerr << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++) {
        if (istradpair(vec[i])) {
            vector<string> tmp;

            tmp.emplace_back(vec[i]);
            tmp.emplace_back(vec[++i]);
            tmp.emplace_back(vec[++i]);
            for (int j = 0; j < 6; j++, i += 2)
                tmp.emplace_back(vec[i]);
            --i;
            tmp.emplace_back(vec[i].substr(2, vec[i].find(' ') - 2));

            mp[tmp[9]].emplace_back(Data({tmp}));
        }

    }
    loadtime();
    for (auto &[name, dat] : mp) {
        sort(dat.begin(), dat.end());
        newfile(name, dat);
    }
    savetime();
    return 0;
}