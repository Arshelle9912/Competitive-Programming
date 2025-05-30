#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), 
    [](const pair<int, int> &a, const pair<int,int> &b) {
        return a.second < b.second;
    });
    multiset<int> ms;
    if (k==0) {
        cout << 0 << "\n";
        return 0;
    }
    ms.insert(0);
    k--;
    int result(0);
    for (int i = 0; i<n; i++) {
        auto it = ms.upper_bound(arr[i].first);
        if (it!=ms.begin()) {
            --it;
            ms.erase(it);
            ms.insert(arr[i].second);
            result++;
        } else if (k>0){
            k--;
            ms.insert(arr[i].second);
            result++;
        }
    }
    cout << result << "\n";
}