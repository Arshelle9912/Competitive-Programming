#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, e;
    cin >> r >> c >> e;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) cin >> grid[i];
    int sr = -1, sc = -1, gr = -1, gc = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'S') { 
                sr = i; sc = j; 
            }
            if (grid[i][j] == 'G') { 
                gr = i; gc = j; 
            }
        }
    }
    auto cost = [&](char ch) -> int {
        if (ch == '#') return -1;
        if (ch == 'F') return 2;
        if (ch == 'M') return 3;
        return 1;
    };
    int n = r * c;
    int inf = 1000000000;
    vector<int> bestDays(n, inf);
    vector<int> bestStamina(n, -1);
    auto id = [&](int i, int j) { 
        return i * c + j; 
    };
    using state = tuple<int,int,int,int>;
    priority_queue<state, vector<state>, greater<state>> pq;
    bestDays[id(sr, sc)] = 1;
    bestStamina[id(sr, sc)] = e;
    pq.push({1, -e, sr, sc});
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        auto [days, negStam, i, j] = pq.top();
        pq.pop();
        int stam = -negStam;
        int v = id(i, j);
        if (days != bestDays[v] || stam != bestStamina[v]) continue;
        if (i == gr && j == gc) {
            cout << days << "\n";
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
            int w = cost(grid[ni][nj]);
            if (w < 0 || w > e) continue;
            int ndays = days;
            int nstam = stam;
            if (nstam >= w) {
                nstam -= w;
            } else {
                ndays += 1;
                nstam = e - w;
            }
            int u = id(ni, nj);
            if (ndays < bestDays[u] ||(ndays == bestDays[u] && nstam > bestStamina[u])) {
                bestDays[u] = ndays;
                bestStamina[u] = nstam;
                pq.push({ndays, -nstam, ni, nj});
            }
        }
    }
    cout << -1 << "\n";
}