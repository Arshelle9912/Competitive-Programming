#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long sum(0);
    int left(0);
    map<int, int> mp;
    vector<int> arr(n);
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++) {
        mp[arr[i]]++;
        while (mp.size()>k) {
            mp[arr[left]]--;
            if (mp[arr[left]]<=0) {
                mp.erase(arr[left]);
            }
            left++;
        }
        sum += i - left + 1;
    }
    cout << sum << endl;
}