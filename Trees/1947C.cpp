#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<int>& subsize, int node, int parent, int &numRemoved, int k) {
    subsize[node] = 1;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(adj, subsize, i, node, numRemoved, k);
            subsize[node] += subsize[i];
        }
    }
    if (node==1) {
        if (subsize[node]<k) {
            numRemoved--;
        }
    } else {
        if (subsize[node]>=k) {
            numRemoved++;
            subsize[node] = 0;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i<n-1; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }
        vector<int> subsize(n+1);
        int low = 1, high = n;
        int ans;
        while (low<=high) {
            int mid = (low+high)/2;
            int numRemoved = 0;
            dfs(adj, subsize, 1, -1, numRemoved, mid);
            if (numRemoved>=k) {
                low=mid+1;
                ans = mid;
            } else {
                high = mid-1;
            }
        }
        cout << ans << "\n";
    }
}