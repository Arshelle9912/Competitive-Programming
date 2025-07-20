#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<vector<long long>> adj(n+1);
    for (long long i = 1; i<n; i++) {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    queue<long long> q;
    vector<bool> visited(n+1);
    q.push(1);
    visited[1] = true;
    long long countB(1), countR(0);
    bool sw = true;
    while (!q.empty()) {
        long long sz = q.size();
        while (sz--) {
            long long node = q.front();
            q.pop();
            for (long long i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    if (sw) {
                        countR++;
                    } else {
                        countB++;
                    }
                }
            }
        }
        sw = !sw;
    }
    cout << countR * countB - (n-1) << "\n";
}