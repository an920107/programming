#include <bits/stdc++.h>
using namespace std;

struct Solve {
    char board[8][8];
    int queen[8]{0}; // the location of queens
    int count = 0;

    bool check(int row, int col) {
        for (int i = 0; i < row; i ++) {
            if (queen[i] == col) return false;
            if (i + queen[i] == row + col) return false;
            if (i - queen[i] == row - col) return false;
        }
        return true;
    }

    void backtrack(int row) {
        for (int col = 0; col < 8; col ++)
            if (board[row][col] == '.')
                if (check(row, col)) {
                    queen[row] = col;
                    if (row == 7) {
                        count ++;
                        queen[row] = 0;
                        return;
                    }
                    backtrack(row + 1);
                    queen[row] = 0;
                }
    }

    inline void solve() {
        backtrack(0);
        cout << count << '\n';
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve solve;
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j ++)
            cin >> solve.board[i][j];
    solve.solve();

    return 0;
}