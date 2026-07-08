#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int r, int c, bool check, int& sz) {
    visited[i][j] = true;
    sz++;
    vector<int> dir1 = {1, 0, -1, 0};
    vector<int> dir2 = {0, -1, 0, 1};
    for (int k = 0; k<4; k++) {
        int nI = i+dir1[k];
        int nJ = j+dir2[k];
        if (nI<0 || nI>=r || nJ<0 || nJ>=c) continue;
        if (grid[nI][nJ]<grid[i][j]) check = false;
        if (grid[nI][nJ]==grid[i][j] && !visited[nI][nJ]) check &= dfs(grid, visited, nI, nJ, r, c, check, sz);
    }
    return check;
}
int main() {
    int c, r;
    cin >> c >> r;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(r, vector<bool>(c));
    int sum = 0;
    int sz = 0;
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            if (!visited[i][j]) {
                if (dfs(grid, visited, i, j, r, c, true, sz)) {
                    sum+=sz;
                }
                sz=0;
            }
        }
    }
    printf("%d\n", sum);
}