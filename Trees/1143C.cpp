#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> checker(n+1);
    int root;
    for (int i = 1; i<=n; i++) {
        int temp, dis;
        cin >> temp >> dis;
        if (temp==-1) {
            root = i;
            checker[i] = dis;
            continue;
        }
        adj[temp].push_back(i);
        checker[i] = dis;
    }
    vector<int> ans;
    for (int i = 1; i<=n; i++) {
        bool check = true;
        if (checker[i]) {
            for (int j : adj[i]) {
                if (!checker[j]) {
                    check = false;
                }
            }
            if (check) {
                ans.push_back(i);
            }
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    if (ans.empty()) {
        cout << -1 << "\n";
    }
}