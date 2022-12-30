#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool isPalindrome(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i ++)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

int palindromeIndex(string s) {
    if (isPalindrome(s))
        return -1;
    for (int i = 0; i < s.length(); i ++) {
        string newStr = s;
        newStr.erase(newStr.begin() + i);
        if (isPalindrome(newStr))
            return i;
    }
    return -1;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout << result << "\n";
    }

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
