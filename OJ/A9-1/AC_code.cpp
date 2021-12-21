#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
    vector<vector<int>> M;
    int r, c;
    Matrix(int _r, int _c) : r(_r), c(_c) {
        M.assign(r, vector<int>(c));
    }
    void init() {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> M[i][j];
    }
    Matrix operator*(const Matrix &x) const {
        Matrix ret(r, x.c); 
        for (int i = 0; i < r; i++)
            for (int j = 0; j < x.c; j++)
                for (int k = 0; k < c; k++)
                    ret.M[i][j] += M[i][k] * x.M[k][j];
        return ret; 
    }
    void print() const {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cout << M[i][j] << " \n"[j == c-1];
    }
};

void solve() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1; 
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Can't be multiplied\n";
        return;
    }
    Matrix A(r1, c1), B(r2, c2);
    A.init();
    B.init();
    (A * B).print();
}

signed main() {
    solve();
    return 0;
}