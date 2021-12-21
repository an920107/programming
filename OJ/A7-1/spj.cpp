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

int spj(FILE *input, FILE *user_output) {
    vector<string> v1, v2;
    const int buf = 1000005;
    char ch[buf];
    while (~fscanf(input, "%s", ch)) {
        v1.emplace_back(string(ch));
    }
    while (~fscanf(user_output, "%s", ch)) {
        v2.emplace_back(string(ch));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1 == v2) return AC;
    else return WA;
}
