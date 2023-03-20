#include <bits/stdc++.h>
using namespace std;

enum Move {
    NONE, ROCK, PAPER, SCISSOR
};

void solve(int n, int k, vector<vector<int>> &games) {
    // result[player] <win, lose>
    vector<pair<int, int>> result(n, {0, 0});
    for (auto &game : games) {
        bitset<4> bs;
        for (auto &move : game) {
			if (move != Move::NONE)
	            bs[move] = 1;
		}

        if (bs.count() == 1)
            continue;

        int winMove, loseMove;
        if (bs[Move::PAPER] == 0) {
            winMove = Move::ROCK;
            loseMove = Move::SCISSOR;
        }
        if (bs[Move::ROCK] == 0) {
            winMove = Move::SCISSOR;
            loseMove = Move::PAPER;
        }
        if (bs[Move::SCISSOR] == 0) {
            winMove = Move::PAPER;
            loseMove = Move::ROCK;
        }

        for (int i = 0; i < n; i ++) {
            if (game[i] == winMove)
                result[i].first ++;
            else if (game[i] == loseMove)
                result[i].second ++;
        }
    }

    for (auto &[win, lose] : result) {
        if (win + lose == 0)
            cout << "-\n";
        else
            cout << setprecision(3) << fixed << (float)win / (win + lose) << '\n';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	bool newline_flag = false;
    int n, k;
    while (cin >> n) {
        if (n == 0)
            break;
        cin >> k;
		if (newline_flag)
			cout << '\n';
		newline_flag = true;

        string move;
        int player;
        vector<vector<int>> games(k * n * (n - 1) / 2, vector<int>(n));
        for (int i = 0; i < games.size(); i ++) {
			for (int j = 0; j < 2; j ++) {
	            cin >> player >> move;
		        player --;
			    if (move[0] == 'r')
				    games[i][player] = Move::ROCK;
	            else if (move[0] == 'p')
		            games[i][player] = Move::PAPER;
	            else
	                games[i][player] = Move::SCISSOR;
			}
        }
        solve(n, k, games);
    }

    return 0;
}
