#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    vector<int> result;
    map<int, int> mp;
    for (int i = 0; i<n; i++) {
        mp[changed[i]]++;
    }
    if (n%2!=0) {
        return vector<int>();
    }
    sort(changed.begin(), changed.end());
    for (int i = 0; i<n; i++) {
        if (mp[changed[i]]==0) {
            continue;
        }
        if (mp[2*changed[i]]==0) {
            return vector<int>();
        }
        mp[changed[i]]--;
        if (mp[changed[i]]==0) {
            mp.erase(changed[i]);
        }
        result.push_back(changed[i]);
        mp[2*changed[i]]--;
        if (mp[2*changed[i]]==0) {
            mp.erase(2*changed[i]);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> changed(n);
    for (int i = 0; i<n; i++) {
        cin >> changed[i];
    }
    vector<int> result = findOriginalArray(changed);
    for (int ans : result) {
        cout << ans << "\n";
    }
}