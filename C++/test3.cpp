#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Matrix {
private:
    int row, col;
    T *elements;

public:
    Matrix(int _row, int _col): row(_row), col(_col) {
        elements = (T*)malloc(row * col * sizeof(T));
    }

    Matrix(int _row, int _col, vector<vector<T>> _vec): row(_row), col(_col) {
        elements = (T*)malloc(row * col * sizeof(T));
        T *iter = elements;
        for (int i = 0; i < row; i ++)
            for (int j = 0; j < col; j ++)
                *(iter ++) = _vec[i][j];
    }

    inline T get(int row, int col) {
        return elements[this->col * row + col];
    }

    inline void set(int row, int col, T val) {
        elements[this->col * row + col] = val;
    }

    void update(vector<vector<T>> vec) {
        T *iter = elements;
        for (int i = 0; i < row; i ++)
            for (int j = 0; j < col; j ++)
                *(iter ++) = vec[i][j];
    }

    Matrix<T> inverse() {
        if (row != col)
            throw invalid_argument("The matrix cannot be inversed");
        
    }

    Matrix<T> operator-() {
        for (int i = row * col - 1; i >= 0; i --)
            elements[i] = -elements[i];
    }

    Matrix<T> operator+(Matrix<T> x) {
        if (this->col != x.col || this->row != x.row)
            throw invalid_argument("The two matrices cannot plus");
        Matrix<T> result(this->row, this->col);
        for (int i = this->row * this->col - 1; i >= 0; i --)
            result.elements[i] = this->elements[i] + x.elements[i];
        return result;
    }

    Matrix<T> operator-(Matrix<T> x) {
        return *this + (-x);
    }

    Matrix<T> operator*(Matrix<T> x) {
        if (this->col != x.row)
            throw invalid_argument("The two matrices cannot multiply");
        Matrix<T> result(this->row, x.col);
        for (int i = 0; i < this->row; i ++) {
            for (int j = 0; j < x.col; j ++) {
                int subtotal = 0;
                for (int k = 0; k < this->col; k ++)
                    subtotal += this->get(i, k) * x.get(k, j);
                result.set(i, j, subtotal);
            }
        }
        return result;
    }

    friend std::ostream &operator<<(std::ostream& os, Matrix<T> x) {
        for (int i = 0; i < x.row; i ++) {
            for (int j = 0; j < x.col; j ++)
                os << x.get(i, j) << (j < x.col ? " " : "");
            os << (i < x.row ? "\n" : "");
        }
        return os;
    }
};

#define STACKSIZE 100

int main() {
    
    Matrix<int> x(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix<int> z(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix<int> y(3, 1, {{1}, {2}, {3}});

    cout << x * (z * y);

    return 0;
}