#include <bits/stdc++.h>
using namespace std;

#define SIZE 7

struct Solve {

    struct Board {
        bool data[SIZE][SIZE]{false};
    };

    string path;
    int count = 0;

    inline bool available(int row, int col, const Board board) {
        return !(row < 0 || row >= SIZE || col < 0 || col >= SIZE
                || board.data[row][col]);
    }

    void dfs(int row, int col, int step, Board board) {
        if (!available(row, col, board)) return;

        if (!available(row - 1, col, board) && !available(row + 1, col, board)
                && available(row, col - 1, board) && available(row, col + 1, board))
            return;
        if (available(row - 1, col, board) && available(row + 1, col, board)
                && !available(row, col - 1, board) && !available(row, col + 1, board))
            return;
        
        if (available(row + 1, col, board) && available(row, col + 1, board)
                && !available(row + 1, col + 1, board))
            return;
        if (available(row + 1, col, board) && available(row, col - 1, board)
                && !available(row + 1, col - 1, board))
            return;
        if (available(row - 1, col, board) && available(row, col + 1, board)
                && !available(row - 1, col + 1, board))
            return;
        if (available(row - 1, col, board) && available(row, col - 1, board)
                && !available(row - 1, col - 1, board))
            return;

        if (row == SIZE - 1 && col == 0) {
            if (step == path.size())
                count ++;
            return;
        }

        board.data[row][col] = true;
        switch (path[step]) {
            case 'U':
                dfs(row - 1, col, step + 1, board);
                break;
            case 'D':
                dfs(row + 1, col, step + 1, board);
                break;
            case 'L':
                dfs(row, col - 1, step + 1, board);
                break;
            case 'R':
                dfs(row, col + 1, step + 1, board);
                break;
            case '?':
            default:
                dfs(row - 1, col, step + 1, board);
                dfs(row + 1, col, step + 1, board);
                dfs(row, col - 1, step + 1, board);
                dfs(row, col + 1, step + 1, board);
                break;
        }
    }

    void solve() {
        Board board;
        dfs(0, 0, 0, board);
        cout << count << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve solve;
    cin >> solve.path;
    solve.solve();

    return 0;
}