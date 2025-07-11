#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for (int i = 0; i<n-1; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1-1].push_back(temp2-1);
            adj[temp2-1].push_back(temp1-1);
            deg[temp1-1]++;
            deg[temp2-1]++;
        }
        queue<int> leaf;
        for (int i = 0; i<n; i++) {
            if (deg[i]<=1) {
                leaf.push(i);
            }
        }
        int count(0);
        vector<bool> removed(n, false);
        for (int i = 1; i<=k && !leaf.empty(); i++) {
            int sz = leaf.size();
            while (sz--) {
                int l = leaf.front();
                leaf.pop();
                removed[l] = true;
                for (int w : adj[l]){
                    if (--deg[w] == 1){
                        leaf.push(w);
                    }
                }
                deg[l] = 0;
            }
        }
        for (int i = 0; i < n; i++){
            if (!removed[i]) {
                count++;
            }
        }
        cout << count << "\n";
    }
}