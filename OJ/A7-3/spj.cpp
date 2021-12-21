#include <bits/stdc++.h>

using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f){
    if (f != NULL) {
        fclose(f);
    }
}

int main(int argc, char *args[]) {
    FILE *input = NULL, *user_output = NULL;
    int result;
    if (argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if (input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);
    
    close_file(input);
    close_file(user_output);
    return result;
}

char dict[8][4] = {
    {'a', 'b', 'c', 0},
    {'d', 'e', 'f', 0},
    {'g', 'h', 'i', 0},
    {'j', 'k', 'l', 0},
    {'m', 'n', 'o', 0},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', 0},
    {'w', 'x', 'y', 'z'}
};

vector<string> solve(string str) {
    vector<string> result, tmp;
    if (str[0] == '1') {
        result.push_back("none");
        return result;
    }
    result.push_back("");
    for (int i = 0; i < str.length(); i ++) {
        for (int x = 0; x < result.size(); x ++) {
            for (int y = 0; y < 4; y ++) {
                if (dict[str[i] - 50][y] != 0) {
                    tmp.push_back(result[x] + dict[str[i] - 50][y]);
                }
            }
        }
        result = tmp;
		tmp.clear();
    }
    return result;
}

int spj(FILE *test_case, FILE *user_output) {
    vector<string> vec;
    char tmp_str[10];
    fscanf(test_case, "%s", tmp_str);
    string input = string(tmp_str);
    while (fscanf(user_output, "%s", tmp_str) != EOF)
        vec.push_back(string(tmp_str));
    vector<string> ans = solve(input);
    sort(vec.begin(), vec.end());
    sort(ans.begin(), ans.end());
    if (ans == vec) return AC;
    else return WA;
}

