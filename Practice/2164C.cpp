#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> a;
        vector<int> b(m);
        vector<int> c(m);
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            a.push(temp);
        }
        for (int i = 0; i<m; i++) {
            cin >> b[i];
        }
        for (int i = 0; i<m; i++) {
            cin >> c[i];
        }
        vector<pair<int, int>> bc(m);
        for (int i = 0; i<m; i++) {
            bc[i] = {b[i], c[i]};
        }
        sort(bc.begin(), bc.end());
        int ans = 0;
        int j = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        while (!a.empty()) {
            int sword = a.top();
            while (j<m && bc[j].first<=sword) {
                pq.push({bc[j].second, bc[j].first});
                j++;
            }
            a.pop();
            if (pq.empty()) continue;
            pair<int, int> top = pq.top();
            pq.pop();
            ans++;
            if (top.first>0) {
                a.push(max(top.first, sword));
            }
        }
        cout << ans << "\n";
    }
}