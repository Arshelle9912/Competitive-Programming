#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<string> s(n);
    for (int i = 0; i<n; i++) {
        cin >> s[i];
        int countS = 0;
        for (int j = 0; j<s[i].length(); j++) {
            if (s[i][j]=='s') {
                countS++;
            }
        }
        arr[i].first = countS;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), [&](const pair<int, int> a, const pair<int, int> b) {
        return a.first * (s[b.second].length()-b.first) > b.first * (s[a.second].length()-a.first);
    });
    int countS = 0;
    long long ans(0);
    for (pair<int, int> p : arr) {
        int index = p.second;
        for (char c : s[p.second]) {
            if (c=='s') {
                countS++;
            } else {
                ans+=countS;
            }
        }
    }
    cout << ans << "\n";
}