#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> vertices(n);
        long long sum = 0;
        for (int i = 0; i<n; i++) {
            cin >> vertices[i].first;
            sum += vertices[i].first;
        }
        for (int i = 0; i<n-1; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            --num1;
            --num2;
            vertices[num1].second += 1;
            vertices[num2].second += 1;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i<n; i++) {
            if (vertices[i].second>1) {
                pq.push({vertices[i].first, vertices[i].second});
            }
        }
        for (int i = 1; i<n; i++) {
            cout << sum << " ";
            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                sum += p.first;
                if (p.second>2) {
                    pq.push({p.first, p.second - 1});
                }
            }
        }
        cout << "\n";
    }
}