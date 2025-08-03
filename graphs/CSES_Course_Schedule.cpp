#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> indegree(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i<d; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i<n; i++) {
        if (indegree[i]==0) {
            q.push(i);
            ans.push_back(i+1);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            indegree[i]--;
            if (indegree[i]==0) {
                q.push(i);
                ans.push_back(i+1);
            }
        }
    }
    bool check = true;
    for (int i : indegree) {
        if (i!=0) {
            check = false;
        }
    }
    if (check) {
        for (int i : ans) {
            cout << i << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}