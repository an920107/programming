#include <bits/stdc++.h>
using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

char tmp[10001];
map<string, int> mp;

int spj(FILE *input, FILE *user_output){
    while (fscanf(input, "%s", tmp) != EOF) {
        string str(tmp);
        if (*str.rbegin() == '.' || *str.rbegin() == ',')
            str = str.substr(0, str.length() - 1);
        for (int i = 0 ; i < str.length(); i ++)
            if ('A' <= str[i] && str[i] <= 'Z')
                str[i] += 32;
        auto iter = mp.find(str);
        if (iter == mp.end())
            mp.insert(make_pair(str, 1));
        else
            iter->second ++;
    }
    int last_count = INT_MAX;
    while (fscanf(user_output, "%s", tmp) != EOF) {
        string str(tmp);

        if (fscanf(user_output, "%s", tmp) == EOF) return WA;
        stringstream ss;
        ss << string(tmp);
        int count;
        ss >> count;
        if (last_count < count) return WA;
        last_count = count;
        auto iter = mp.find(str);
        if (iter->second != count) return WA;
        mp.erase(iter);
    }
    if (!mp.empty()) return WA;
    return AC;
}

int main() {
    cout << spj(fopen("C++/in", "r"), fopen("C++/out", "r"));
    return 0;
}