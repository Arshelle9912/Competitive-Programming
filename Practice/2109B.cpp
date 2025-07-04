#include <bits/stdc++.h>
using namespace std;
int count(int n) {
    int turns = 0;
    while (n > 1) {
        n = (n + 1) / 2;
        turns++;
    }
    return turns;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col, posRow, posCol;
        cin >> row >> col >> posRow >> posCol;
        long long best = LLONG_MAX;
        best = min(best, (long long)count(posCol) + count(row));
        best = min(best, (long long)count(col-posCol+1) + count(row));
        best = min(best, (long long)count(col) + count(posRow));
        best = min(best, (long long)count(col) + count(row-posRow+1));
        cout << (1 + best) << "\n";
    }
}