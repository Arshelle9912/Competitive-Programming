#include <bits/stdc++.h>
using namespace std;
long long total = 0;
bool checker(int colMask, int diag1Mask, int diag2Mask,int col, int row, vector<vector<char>>& board) {
    int n = board.size();
    if (col>=n || row>=n) return false;
    int d1 = row-col+n-1;
    int d2 = row+col;
    return !(colMask&(1<<col)) && !((1<<d1)&diag1Mask) && !((1<<d2)&diag2Mask) && (board[row][col]!='h');
}
void backtrack(int n, vector<vector<char>>& board, int row, int colMask, int diag1Mask, int diag2Mask) {
    if (row==n) {
        total++;
        return;
    }
    for (int i = 0; i<n; i++) {
        if (checker(colMask, diag1Mask, diag2Mask, i, row, board)) {
            int d1 = row - i + n - 1;
            int d2 = row + i;
            backtrack(n, board, row+1, colMask|(1<<i), diag1Mask|(1<<d1), diag2Mask|(1<<d2));
        }
    }
}
int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n==0 && m==0) break;
        vector<vector<char>> board(n, vector<char> (n, '.'));
        for (int i = 0; i<m; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            board[temp1][temp2] = 'h';
        }
        backtrack(n, board, 0, 0, 0, 0);
        cout << total << "\n";
        total = 0;
    }
}