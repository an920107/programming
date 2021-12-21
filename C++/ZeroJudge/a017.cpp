#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define ARR_MAX 100

using namespace std;

int main() {
    string str, buf, opr[ARR_MAX];
    stringstream ss;
    int num, begin, end, loc, bufa, bufb;
    bool par_flag, md_flag;
    while (getline(cin, str)) {
        for (int i = 0; i < ARR_MAX; i++) {
            opr[i] = "";
        }
        ss.clear();
        ss.str(str);
        num = 0;
        while (getline(ss, buf, ' ')) {
            opr[num] = buf;
            num++;
        }
        while (num > 1) {
            //找括弧
            begin = 0, end = num - 1;
            par_flag = false;
            for (int i = 0; i < num; i++) {
                if (opr[i] == ")") {
                    end = i;
                    par_flag = true;
                    break;
                }
            }
            if (par_flag) {
                for (int i = end; i >= 0; i--) {
                    if (opr[i] == "(") {
                        begin = i;
                        break;
                    }
                }
            }
            if (par_flag && end - begin == 2) {
                for (int i = end; i < num; i++)
                    opr[i] = opr[i + 1];
                num--;
                for (int i = begin; i < num; i++)
                    opr[i] = opr[i + 1];
                num--;
            }
            //找運算中心
            loc = 1;
            md_flag = false;
            for (int i = begin; i <= end; i++) {
                if (opr[i] == "*" || opr[i] == "/" || opr[i] == "%") {
                    loc = i;
                    md_flag = true;
                    break;
                }
            }
            if (!md_flag) {
                for (int i = begin; i <= end; i++) {
                    if (opr[i] == "+" || opr[i] == "-") {
                        loc = i;
                        break;
                    }
                }
            }
            //計算
            ss.clear();
            ss.str(opr[loc - 1]);
            ss >> bufa;
            ss.clear();
            ss.str(opr[loc + 1]);
            ss >> bufb;
            switch (opr[loc][0]) {
            case '*':
                opr[loc - 1] = to_string(bufa * bufb);
                break;
            case '/':
                opr[loc - 1] = to_string(bufa / bufb);
                break;
            case '%':
                if ((bufa > 0 && bufb < 0) || (bufa < 0 && bufb > 0))
                    opr[loc - 1] = to_string(bufa % bufb + bufb);
                else
                    opr[loc - 1] = to_string(bufa % bufb);
                break;
            case '+':
                opr[loc - 1] = to_string(bufa + bufb);
                break;
            case '-':
                opr[loc - 1] = to_string(bufa - bufb);
                break;
            default:
                break;
            }
            //移位
            for (int i = loc; i < num; i++)
                opr[i] = opr[i + 2];
            num -= 2;
            end -= 2;
            if (par_flag && end - begin == 2) {
                for (int i = end; i < num; i++)
                    opr[i] = opr[i + 1];
                num--;
                for (int i = begin; i < num; i++)
                    opr[i] = opr[i + 1];
                num--;
            }
        }
        cout << opr[0] << '\n';
    }
    return 0;
}
