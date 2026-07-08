#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, r;
    cin >> n >> k >> r;
    map<int, int> window;
    map<int, int> mp;
    vector<int> arr(n);
    int ans = INT_MAX;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<r; i++) {
        int key, freq;
        cin >> key >> freq;
        mp[key] = freq;
    }
    int low = 0;
    int met = 0;
    set<int> s;
    for (int i = 0; i<n; i++) {
        if (mp.find(arr[i])!=mp.end()) {
            window[arr[i]]++;
            if (mp[arr[i]]<=window[arr[i]] && s.find(arr[i])==s.end()) {
                met++;
                s.insert(arr[i]);
            }
        }
        while (met==r) {
            ans = min(ans, i-low+1);
            if (mp.find(arr[low])!=mp.end()) {
                window[arr[low]]--;
                if (window[arr[low]]<mp[arr[low]] && s.find(arr[low])!=s.end()) {
                    s.erase(arr[low]);
                    met--;
                }
            }
            low++;
        }
    }
    if (ans==INT_MAX) {
        cout << "impossible" << "\n";
        return 0;
    }
    cout << ans << "\n";
}