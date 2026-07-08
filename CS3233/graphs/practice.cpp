#include <bits/stdc++.h>
using namespace std;
int floodfill(vector<string>& grid, vector<vector<bool>>& visited, int i, int j) {
    int r = grid.size();
    int c = grid[0].size();
    visited[i][j] = true;
    int total = 0;
    vector<int> dir1 = {1, -1, 0, 0};
    vector<int> dir2 = {0, 0, -1, 1};
    for (int k = 0; k<4; k++) {
        int nI = i+dir1[k];
        int nJ = j+dir2[k];
        if (nI<0 || nI>=r || nJ<0 || nJ>=c) continue;
        if (visited[nI][nJ]) continue;
        if (grid[nI][nJ]=='T') return total;
    }
    for (int k = 0; k<4; k++) {
        int nI = i+dir1[k];
        int nJ = j+dir2[k];
        if (nI<0 || nI>=r || nJ<0 || nJ>=c) continue;
        if (visited[nI][nJ]) continue;
        if (grid[nI][nJ]=='.') total+=floodfill(grid, visited, nI, nJ);
        if (grid[nI][nJ]=='G') {
            total++;
            total+=floodfill(grid, visited, nI, nJ);
        }
    }
    return total;
}
int main() {
    int c, r;
    cin >> c >> r;
    vector<string> grid(r);
    for (int i = 0; i<r; i++) {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(r, vector<bool> (c));
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            if (grid[i][j]=='P') {
                printf("%d\n", floodfill(grid, visited, i, j));
                return 0;
            }
        }
    }
}