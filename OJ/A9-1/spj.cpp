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

int x_m, x_n, y_m, y_n;
int arr_x[5][5], arr_y[5][5];

int ArrMulti(int m, int n) {
    int sum = 0;
    for (int i = 0; i < x_n; i ++)
        sum += arr_x[m][i] * arr_y[i][n];
    return sum;
}

vector<string> solve(vector<int> vec) {
    vector<string> result;
    int loc = 0;
    x_m = vec[loc ++];
    x_n = vec[loc ++];
    y_m = vec[loc ++];
    y_n = vec[loc ++];
    if (x_n != y_m) {
        result.push_back("Can't be multiplied");
        return result;
    }
    for (int i = 0; i < x_m; i ++)
        for (int j = 0; j < x_n; j ++)
            arr_x[i][j] = vec[loc ++];
    for (int i = 0; i < y_m; i ++)
        for (int j = 0; j < y_n; j ++)
            arr_y[i][j] = vec[loc ++];
    for (int i = 0; i < x_m; i ++) {
        result.push_back("");
        for (int j = 0; j < y_n; j ++) {
            result[i] += to_string(ArrMulti(i, j));
            if (j != y_n - 1) result[i] += ' ';
        }
    }
    return result;
}

int spj(FILE *input, FILE *user_output) {
    vector<int> input_vec;
    vector<string> vec;
    int tmp;
    char str[1000];
    while (fscanf(input, "%d", &tmp) != EOF) {
        input_vec.push_back(tmp);
    }
    while (fgets(str, 1000, user_output) != NULL) {
        vec.push_back(string(str));
    }
    vector<string> ans = solve(input_vec);
    for (int i = 0; i < vec.size(); i ++) {
        while (vec[i][vec[i].length() - 1] == '\n')
            vec[i].pop_back();
        while (vec[i][vec[i].length() - 1] == ' ')
            vec[i].pop_back();
    }
    if (ans == vec) return AC;
    else return WA;
}