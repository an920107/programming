#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &str) {
    for (char ch : str)
        if (!(ch >= '0' && ch <= '9'))
            return false;
    return true;
}

vector<string> split(const string &str, char regex) {
    string curr = "";
    vector<string> vec;
    for (char ch : str) {
        if (ch == regex) {
            vec.emplace_back(curr);
            curr = "";
        }
        else curr += ch;
    }
    vec.emplace_back(curr);
    return vec;
}


int main() {

    string line, currentId;

    freopen("traders_data.txt", "r", stdin);
    freopen("test.sql", "w", stdout);

    cout << "USE `test`;\n";

    while (getline(cin, line)) {
        if (isNumber(line)) {
            currentId = line;
        }
        else {
            vector<string> vec = split(line, ' ');
            if (vec[0].find('/') == string::npos) continue;
            cout << "REPLACE INTO `trading_history` VALUES(\n"
                << "\t" << currentId << ",\n"
                << "\t\'" << vec[0] << "\',\n"
                << "\t" << vec[1].substr(1, vec[1].length() - 3) << ",\n"
                << "\t" << ((vec[2] == "Long") ? "1" : "0") << ",\n"
                << "\t" << vec[3] << ",\n"
                << "\t" << vec[4] << ",\n"
                << "\t\'2022-" << vec[5].substr(0, 2) << "-" << vec[5].substr(3, 2) << " " << vec[6] << "\',\n"
                << "\t\'2022-" << vec[7].substr(0, 2) << "-" << vec[7].substr(3, 2) << " " << vec[8] << "\',\n"
                << "\t" << vec[9].substr(0, vec[9].length() - 1) << "\n"
                << ");\n";
        }
    }

    return 0;
}
