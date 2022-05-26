#include <bits/stdc++.h>
using namespace std;

struct Info {

    string id = "";
    string name = "";
    string profit = "";
    string photo = "";
};

int main() {
    vector<Info> infos;
    string line;

    freopen("traders_id.txt", "r", stdin);
    while (getline(cin, line)) {
        infos.emplace_back(Info());
        infos.back().id = line;
    }
    cin.clear();

    system("iconv -f utf8 -t big5 -o traders_name_big5.txt traders_name.txt");
    freopen("traders_name_big5.txt", "r", stdin);
    for (int i = 0; i < infos.size(); i ++) {
        getline(cin, line);
        infos[i].name = line;
    }
    cin.clear();

    freopen("traders_profit.txt", "r", stdin);
    for (int i = 0; i < infos.size(); i ++) {
        getline(cin, line);
        infos[i].profit = line;
    }
    cin.clear();

    freopen("traders_photo_src.txt", "r", stdin);
    for (int i = 0; i < infos.size(); i ++) {
        getline(cin, line);
        infos[i].photo = line;
    }
    cin.clear();

    system("mkdir -p info photo");
    system("rm photo/*");
    for (auto info : infos) {
        freopen(("info/" + info.id).c_str(), "w", stdout);
        cout << info.name << '\n' << info.profit << '\n';
        cout.clear();
        system(("wget -O photo/" + info.id + ".jpg " + info.photo).c_str());
    }
}
