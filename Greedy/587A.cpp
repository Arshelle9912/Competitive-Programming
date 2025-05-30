#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> freq(1e6+26);
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        freq[temp]++;
    }
    for (int i = 0; i<1000025; i++) {
        long long pairs = freq[i] / 2;
        freq[i] %= 2;
        freq[i+1] += pairs;
    }
    int ans(0);
    for (int x:freq) {
        ans+=x;
    }
    cout << ans << "\n";
}