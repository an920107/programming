#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 26
#define MIN_SIZE 5
#define FLAG_SIGN 35 // #
#define CURSOR_SIGN 88 // X
#define BACKGROUND_SIGN 32 // Space
#define OCCUPIED_SIGN 46 // .

using namespace std;

int main() {
    
    /** 變數初始化 **/
    srand(time(NULL));
    int m = 0, n = 0, c = 0;
    int rnd_x, rnd_y, loc_x, loc_y;
    int x[MAX_SIZE + 2][MAX_SIZE + 2]; // -1: 地雷, -2: 已開啟, -3: 牆壁
    int x_tag[MAX_SIZE + 2][MAX_SIZE + 2];
    char x_dp[MAX_SIZE + 2][MAX_SIZE + 2];
    char key_input, _key_input, last_dp;
    bool find, win, judge;
    for (int i = 0; i < MAX_SIZE + 2; i++) {
        for (int j = 0; j < MAX_SIZE + 2; j++) {
            x[i][j] = 0;
            x_tag[i][j] = -1;
            x_dp[i][j] = BACKGROUND_SIGN;
        }
    }

    /** 參數輸入 **/
    do {
        cout << "Enter the width and height. ("
             << MIN_SIZE << "~" << MAX_SIZE << ")\nWidth: ";
        cin >> m; 
        cout << "Height: ";
        cin >> n;
    } while (m > MAX_SIZE || n > MAX_SIZE || m < MIN_SIZE || n < MIN_SIZE);
    do {
        cout << "Number of minesweepers: ";
        cin >> c;
    } while (c <= 0 || c >= m * n - 10);

    /** 地雷生成 **/
    for (int i = 0; i < c; ) {
        rnd_x = rand() % m + 1;
        rnd_y = rand() % n + 1;
        if (x[rnd_x][rnd_y] == 0) {
            x[rnd_x][rnd_y] = -1;
            i++;
        }
    }

    /** 計算周邊地雷數 **/
    for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (x[i][j] == 0) {
            for (int i_at = -1; i_at <= 1; i_at++) {
            for (int j_at = -1; j_at <= 1; j_at++) {
                if (i_at == 0 && j_at == 0)
                    continue;
                else if (x[i + i_at][j + j_at] == -1)
                    x[i][j]++;
            }}
        }
    }}

    /** 初始化盤面 **/
    for (int i = 1; i <= m; i++) {
        x_dp[i][0] = i + 64;
        x_dp[i][n + 1] = i + 64;
        x[i][0] = -3;
        x[i][n + 1] = -3;
    }
    for (int j = 1; j <= n; j++) {
        x_dp[0][j] = j + 96;
        x_dp[m + 1][j] = j + 96;
        x[0][j] = -3;
        x[m + 1][j] = -3;
    }
    x[0][0] = -3;
    x[0][n + 1] = -3;
    x[m + 1][0] = -3;
    x[m + 1][n + 1] = -3;
    x_dp[0][0] = ' ';
    x_dp[0][n + 1] = ' ';
    x_dp[m + 1][0] = ' ';
    x_dp[m + 1][n + 1] = ' ';
    loc_x = 1;
    loc_y = 1;
    last_dp = x_dp[loc_x][loc_y];
    x_dp[loc_x][loc_y] = CURSOR_SIGN;

    /** 遊戲主程式 **/
    while (true) {

        /** 輸出入 **/
        while (true) {
            judge = false;
            system("cls");
            printf("\nCursor location: %c / %c\n", loc_x + 64, loc_y + 96);
            printf("Current: %c\n\n", last_dp);
            for (int i = 0; i <= m + 1; i++) {
                for (int j = 0; j <= n + 1; j++) {
                    printf("%c  ", x_dp[i][j]);
                    // cout << x_dp[i][j] << "  ";
                }
                printf("\n");
            }
            printf("\nWASD/Arrow: move\nSpace: flag\nEnter: return\nCtrl-C: quit\n\n");
            key_input = getche();
            if (key_input == 0) {
                key_input = getche();
                switch (key_input) {
                case 72: // Up
                    key_input = 'W';
                    break;
                case 75: // Left
                    key_input = 'A';
                    break;
                case 80: // Down
                    key_input = 'S';
                    break;
                case 77: // Right
                    key_input = 'D';
                    break;
                default:
                    break;
                }
            }
            switch (key_input) {
            case ' ': // Space
                if (last_dp == BACKGROUND_SIGN) {
                    last_dp = FLAG_SIGN;
                    x_dp[loc_x][loc_y] = FLAG_SIGN;
                }
                else if (last_dp == FLAG_SIGN) {
                    last_dp = BACKGROUND_SIGN;
                    x_dp[loc_x][loc_y] = BACKGROUND_SIGN;
                }
                break;
            case 'W':
            case 'w':
                x_dp[loc_x][loc_y] = last_dp;
                loc_x--;
                if (loc_x == 0) loc_x = m;
                last_dp = x_dp[loc_x][loc_y];
                x_dp[loc_x][loc_y] = CURSOR_SIGN;
                break;
            case 'A':
            case 'a':
                x_dp[loc_x][loc_y] = last_dp;
                loc_y--;
                if (loc_y == 0) loc_y = n;
                last_dp = x_dp[loc_x][loc_y];
                x_dp[loc_x][loc_y] = CURSOR_SIGN;
                break;
            case 'S':
            case 's':
                x_dp[loc_x][loc_y] = last_dp;
                loc_x++;
                if (loc_x == m + 1) loc_x = 1;
                last_dp = x_dp[loc_x][loc_y];
                x_dp[loc_x][loc_y] = CURSOR_SIGN;
                break;
            case 'D':
            case 'd':
                x_dp[loc_x][loc_y] = last_dp;
                loc_y++;
                if (loc_y == n + 1) loc_y = 1;
                last_dp = x_dp[loc_x][loc_y];
                x_dp[loc_x][loc_y] = CURSOR_SIGN;
                break;
            case '\r': // Enter
                judge = true;
                break;
            case 3: // Ctrl + C
                return 0;
            default:
                break;
            }
            if (judge) break;
        }

        /** 單格顯示 **/
        if (x[loc_x][loc_y] > 0) {
            x_dp[loc_x][loc_y] = x[loc_x][loc_y] + 48; 
            last_dp = x_dp[loc_x][loc_y];
            x[loc_x][loc_y] = -2;
        }

        /** 0 點擴散 **/
        else if (x[loc_x][loc_y] == 0) {
            x_tag[loc_x][loc_y] = 0;
            last_dp = OCCUPIED_SIGN;
            find = true;
            for (int count = 0; find; count++) {
                find = false;
                for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if ((x_dp[i][j] == OCCUPIED_SIGN || x[i][j] == 0) && x_tag[i][j] == count) {
                        find = true;
                        for (int i_at = -1; i_at <= 1; i_at++) {
                        for (int j_at = -1; j_at <= 1; j_at++) {
                            if (i_at == 0 && j_at == 0) {
                                if (x[i][j] == 0) x_dp[i][j] = OCCUPIED_SIGN;
                                else x_dp[i][j] = x[i][j] + 48;
                                x[i][j] = -2;
                            }
                            else if (x[i + i_at][j + j_at] >= 0 && x_tag[i + i_at][j + j_at] == -1) {
                                if (x[i + i_at][j + j_at] == 0) x_dp[i + i_at][j + j_at] = OCCUPIED_SIGN;
                                else x_dp[i + i_at][j + j_at] = x[i + i_at][j + j_at] + 48;
                                x_tag[i + i_at][j + j_at] = count + 1;
                                x[i + i_at][j + j_at] = -2;
                            }
                        }}
                    }
                }}
            }
            for (int i = 0; i < MAX_SIZE + 2; i++) {
                for (int j = 0; j < MAX_SIZE + 2; j++) {
                    x_tag[i][j] = -1;
                }
            }
        }

        /** 遊戲結束 **/
        else if (x[loc_x][loc_y] == -1 && last_dp != FLAG_SIGN) {
            cout << "Boom! Game over!\n\n";
            break;
        }

        /** 勝利判斷 **/
        win = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (x_dp[i][j] == BACKGROUND_SIGN && x[i][j] != -1) {
                    win = false;
                    break;
                }
            }
        }
        if (win) {
            cout << "Congradulation! You win!\n\n";
            break;
        }
    }
    return 0;
}
