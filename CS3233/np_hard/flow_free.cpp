#include <bits/stdc++.h>
using namespace std;

static const int N = 4;
static const int NEG_INF = -1000000000;

int numColors = 3;                  
int cell[16];                   
vector<int> endpoints[4];
vector<int> adj[16];

int memo[16][1 << 16];
int seen[16][1 << 16];
int stamp = 1;

int id(int r, int c) {
    return r * 4 + c;
}

int colorId(char ch) {
    if (ch == 'R') return 0;
    if (ch == 'G') return 1;
    if (ch == 'B') return 2;
    if (ch == 'Y') return 3;
    return 4;
}
int dp(int u, int mask, int color) {
    if (seen[u][mask] == stamp) return memo[u][mask];
    seen[u][mask] = stamp;

    if (u == endpoints[color][1]) {
        return memo[u][mask] = __builtin_popcount((unsigned)mask);
    }

    int best = NEG_INF;
    for (int v : adj[u]) {
        if (cell[v] != color) continue;
        if (mask & (1 << v)) continue;
        best = max(best, dp(v, mask | (1 << v), color));
    }

    return memo[u][mask] = best;
}

int longestPathForColor(int color) {
    int start = endpoints[color][0];
    return dp(start, 1 << start, color);
}

bool checkFilledBoard() {
    ++stamp;

    int totalCovered = 0;
    for (int c = 0; c < numColors; c++) {
        int len = longestPathForColor(c);
        if (len < 0) return false;  
        totalCovered += len;
    }

    return totalCovered == 16;
}

bool backtrack(int pos) {
    if (pos == 16) return checkFilledBoard();

    if (cell[pos] != 4) return backtrack(pos + 1);

    for (int c = 0; c < numColors; c++) {
        cell[pos] = c;
        if (backtrack(pos + 1)) return true;
    }

    cell[pos] = 4;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int r = 0; r < N; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < N; c++) {
            int u = id(r, c);
            cell[u] = colorId(s[c]);

            if (s[c] == 'Y') numColors = 4;
            if (cell[u] != 4) endpoints[cell[u]].push_back(u);
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int u = id(r, c);
            if (r > 0) adj[u].push_back(id(r - 1, c));
            if (r + 1 < N) adj[u].push_back(id(r + 1, c));
            if (c > 0) adj[u].push_back(id(r, c - 1));
            if (c + 1 < N) adj[u].push_back(id(r, c + 1));
        }
    }

    cout << (backtrack(0) ? "solvable" : "not solvable") << '\n';
    return 0;
}