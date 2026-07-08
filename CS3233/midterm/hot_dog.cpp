#include <bits/stdc++.h>
using namespace std;
bool checker(vector<vector<int>>& dist, int val) {
    int h = dist.size();
    int w = dist[0].size();
    int minS = INT_MAX;
    int maxS = INT_MIN;
    int minT = INT_MAX;
    int maxT = INT_MIN;
    int cnt = 0;
    for (int i = 0; i<h; i++) {
        for (int j = 0; j<w; j++) {
            if (dist[i][j]>=val) {
                cnt++;
                minS = min(i+j, minS);
                maxS = max(i+j, maxS);
                minT = min(i-j, minT);
                maxT = max(i-j, maxT);
            }
        }
    }
    if (cnt<2) return false;
    int d = max(maxS-minS, maxT-minT);
    return d>=val;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w, h;
        cin >> n >> w >> h;
        vector<pair<int, int>> pos(n);
        for (int i = 0; i<n; i++) {
            cin >> pos[i].second >> pos[i].first;
        }
        queue<pair<int, int>> q;
        vector<vector<int>> dist(h, vector<int> (w, INT_MAX));
        for (int i = 0; i<n; i++) {
            q.push(pos[i]);
            dist[pos[i].first][pos[i].second] = 0;
        }
        vector<int> dir1 = {-1, 1, 0, 0};
        vector<int> dir2 = {0, 0, -1, 1};
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (int i = 0; i<4; i++) {
                int nI = front.first + dir1[i];
                int nJ = front.second + dir2[i];
                if (nI<0 || nI>=h || nJ<0 || nJ>=w) continue;
                if (dist[nI][nJ]!=INT_MAX) continue;
                dist[nI][nJ] = dist[front.first][front.second]+1;
                q.push({nI, nJ});
            }
        }
        int high = 2000;
        int low = 0;
        int ans;
        while (low<=high) {
            int mid = (low+high)/2;
            if (checker(dist, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        printf("%d\n", ans);
    }
}