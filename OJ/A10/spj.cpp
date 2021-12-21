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

struct Link {
    char value;
    Link *lastPtr;
    Link *nextPtr;
};

class Stack {
private:
    Link *lnk = new Link;
    int size = 0;

public:
    void push(char ch) {
        Link *tmp = lnk;
        lnk = new Link;
        lnk->value = ch;
        lnk->lastPtr = tmp;
        tmp->nextPtr = lnk;
        size ++;
    }

    string pop() {
        if (size == 0) return "empty";
        string result = "";
        Link *tmp = lnk->lastPtr;
        result += lnk->value;
        delete(lnk);
        lnk = tmp;
        size --;
        return result;
    }

    string list() {
        if (size == 0) return "";
        string result = "", tmp_str;
        Link *irr = lnk;
        for (int i = 0; i < size - 1; i ++) {
            irr = irr->lastPtr;
        }
        for (int i = 0; i < size - 1; i ++) {
            tmp_str = irr->value;
            result += tmp_str + " ";
            irr = irr->nextPtr;
        }
        tmp_str = irr->value;
        result += tmp_str;
        return result;
    }
};

vector<string> solve(vector<string> input) {
    char ch;
    Stack stk;
    vector<string> result;
    for (int i = 0; i < input.size(); i ++) {
        if (input[i] == "push")
            stk.push(input[++ i][0]);
        else if (input[i] == "pop")
            result.push_back(stk.pop());
        else if (input[i] == "list")
            result.push_back(stk.list());
        else break;
    }
    return result;
}

int spj(FILE *test_input, FILE *user_output) {
    vector<string> input, vec;
    char str[10000];
    while (fscanf(test_input, "%s", str) != EOF) {
        input.push_back(string(str));
    }
    while (fgets(str, 10000, user_output) != NULL) {
        vec.push_back(string(str));
    }
    for (int i = 0; i < vec.size(); i ++) {
        if (vec[i].length() > 0) {
            while (vec[i][vec[i].length() - 1] == '\n')
                vec[i].pop_back();
            while (vec[i][vec[i].length() - 1] == ' ')
                vec[i].pop_back();
        }
    }
    vector<string> ans = solve(input);
    if (ans == vec) return AC;
    else return WA;
}