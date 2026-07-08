#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

struct Matrix {
    vector<vector<ll>> mat;
    int rows, cols;

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        mat.assign(r, vector<ll>(c, 0));
    }

    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 0; i < n; i++) I.mat[i][i] = 1;
        return I;
    }
};

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int k = 0; k < A.cols; k++) {
            for (int j = 0; j < B.cols; j++) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix base, long long exp) {
    Matrix result = Matrix::identity(base.rows);
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;

    Matrix A(2, 2);
    A.mat[0][0] = 1; A.mat[0][1] = 1;
    A.mat[1][0] = 1; A.mat[1][1] = 0;

    Matrix res = power(A, n - 1);
    return res.mat[0][0];
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << '\n';
}