#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> order(n+1);
    for (int i = 0; i<n; i++) {
        cin >> order[i];
    }
    vector<int> index(n+1);
    for (int i = 0; i<n; i++) {
        index[order[i]] = i;
    }
    for (int i = 1; i<=n; i++) {
        if (adj[i].size()==0) continue;
        sort(adj[i].begin(), adj[i].end(), [&] (int a, int b){
            return index[a] < index[b];
        });
    }
    vector<bool> visited(n+1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int ind = 1;
    bool check = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                if (order[ind]!=i) {
                    check = false;
                    break;
                }
                ind++;
                q.push(i);
            }
        }
    }
    if (check) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}