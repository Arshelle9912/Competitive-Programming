#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> adj(n);
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    char dirChar[] = {'R','L','U','D'};
    pair<int, int> start;
    for (int i = 0; i<n; i++) {
        cin >> adj[i];
        for (int j = 0; j<m; j++) {
            if (adj[i][j]=='A') {
                start = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> parent(n, vector<int> (m));
    vector<vector<int>> visited(n, vector<int> (m));
    bool check = false;
    int checkR;
    int checkC;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> front = q.front();
            int r = front.first, c = front.second;
            q.pop();
            if (!visited[r][c]) {
                visited[r][c] = true;
                for (int i = 0; i<4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    if (nr < 0 || nr>=n || nc < 0 || nc>=m) continue;
                    if (adj[nr][nc]=='#') continue;
                    if (visited[nr][nc]) continue;
                    q.push({nr, nc});
                    parent[nr][nc] = i;
                    if (adj[nr][nc]=='B') {
                        check = true;
                        checkR = nr;
                        checkC = nc;
                        break;
                    }
                }
            }
            if (check) {
                break;
            }
        }
        if (check) {
            break;
        }
    }
    string ans = "";
    if (!check) {
        cout << "NO" << "\n";
        return 0;
    }
    while (checkR!=start.first || checkC!=start.second) {
        int i = parent[checkR][checkC];
        ans += dirChar[i];                    // append the correct opposite move
        checkR -= dx[i];
        checkC -= dy[i];
    }
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    for (int i = ans.size()-1; i>=0; i--) {
        cout << ans[i];
    }
}