#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> arr(n);
        map<int, int> mp;
        int result(INT_MAX);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i<d; i++) {
            mp[arr[i]]++;
        }
        result = min(result, (int)mp.size());
        for (int i = d; i<n; i++) {
            mp[arr[i]]++;
            mp[arr[i-d]]--;
            if (mp[arr[i-d]]==0) {
                mp.erase(arr[i-d]);
            }
            result = min(result, (int)mp.size());
        }
        cout << result << endl;
    }
}