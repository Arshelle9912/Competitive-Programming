#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 2; i<=n; i++) {
        int temp;
        cin >> temp;
        adj[temp-1].push_back(i);
    }
    bool check = true;
    for (vector<int> v : adj) {
        if (v.empty()) {
            continue;
        }
        int count(0);
        for (int i : v) {
            if (adj[i-1].empty()) {
                count++;
            }
        }
        if (count < 3) {
            check = false;
            break;
        }
    }
    if (check) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}