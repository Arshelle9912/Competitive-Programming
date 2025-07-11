#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> level(n+1);
    vector<int> levels(n+1);
    for (int i = 2; i<=n; i++) {
        int parent;
        cin >> parent;
        level[i] = level[parent]+1;
        levels[level[i]]++;
    }
    int ans(0);
    for (int i = 1; i<=n; i++) {
        if (levels[i]%2!=0) {
            ans++;
        }
    }
    cout << ans + 1 << "\n";
}