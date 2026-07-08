#include <bits/stdc++.h>
using namespace std;
bool backtracking(int colors, vector<vector<int>>& adj, vector<int>& colored, int index) {
    int n = adj.size();
    if (index>=n) return true;
    for (int i = 0; i<colors; i++) {
        bool check = true;
        for (int border : adj[index]) {
            if (colored[border]==i) {
                check = false;
                break;
            }
        }
        if (check) {
            colored[index] = i;
            if (backtracking(colors, adj, colored, index+1)) return true;
            colored[index] = -1;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj(n);
        for (int i = 0; i<e; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            adj[num1].push_back(num2);
            adj[num2].push_back(num1);
        }
        bool check = true;
        for (int i = 1; i<=4; i++) {
            vector<int> colored(n, -1);
            colored[0] = 0;
            if (backtracking(i, adj, colored, 0)) {check = false; printf("%d\n", i); break;}
        }
        if (check) printf("many\n");
    }
}