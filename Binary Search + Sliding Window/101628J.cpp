#include <bits/stdc++.h>
using namespace std;

bool checker(vector<vector<int>> arr, int mid, long long k) {
    multiset<pair<int, int>> ms;
    int n = arr.size();
    long long cost = 0;
    int right = n-1;
    for (int i = 0; i<n; i++) {
        if (arr[i][0]>mid) {
            int need = arr[i][0]-mid;
            while (right>i && arr[right][0]<mid) {
                pair<int, int> temp = {arr[right][2], mid-arr[right][0]};
                ms.insert(temp);
                right--;
            }
            while (need > 0 && !ms.empty()) {
                auto it = ms.begin();
                int c_j = it->first;
                int cap = it->second;
                ms.erase(it);
                int use = min(cap, need);
                cost += (long long)use * (arr[i][1] + c_j);
                if (cost > k) return false;
                need -= use;
                if (cap > use) {
                    ms.insert({ c_j, cap - use });
                }
            }
            if (need > 0) return false;
        } else {
            break;
        }
    }
    return true;
}
int main () {
    long long n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin(), arr.end(), greater<vector<int>>());
    long long low = 0; long long high = 1000000;
    long long ans = INT_MAX;
    while (low<=high) {
        long long mid = (low+high)/2;
        if (checker(arr, mid, k)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}