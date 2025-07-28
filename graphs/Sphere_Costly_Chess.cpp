#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    vector<int> dx = { 2, 2, -2, -2,  1,  1, -1, -1 };
    vector<int> dy = { 1,-1,  1, -1,  2, -2,  2, -2 };
    while (cin >> a >> b >> c >> d) {
        vector<vector<int>> dist(8, vector<int> (8, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.emplace(0, pair<int,int>(a, b));
        dist[a][b] = 0;
        while (!pq.empty()) {
            auto [cost, coord] = pq.top();
            auto [n, m] = coord;
            pq.pop();
            if (cost>dist[n][m]) continue;
            for (int i = 0; i<8; i++) {
                int newN = n + dx[i];
                int newM = m + dy[i];
                if (newN<0 || newN>=8 || newM<0 || newM>=8) continue;
                if (dist[newN][newM] > cost + n*newN + m*newM) {
                    dist[newN][newM] = cost + n*newN + m*newM;
                    pq.emplace(dist[newN][newM], pair<int, int> (newN, newM));
                }
            }
        }
        cout << dist[c][d] << "\n";
    }
}