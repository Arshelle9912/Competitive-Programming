#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxi = 0;
    int maxIndex = 0;
    for (int i = 0; i<n; i++) {
        cin >> arr[i]; 
        if (arr[i]>maxi) {
            maxi = arr[i];
            maxIndex = i;
        }
    }
    stack<pair<int, int>> st1;
    stack<pair<int, int>> st2;
    int ans = 0;
    for (int i = maxIndex; i>=0; i--) {
        int max_j = 0;
        while (!st1.empty() && arr[i]>=st1.top().first) {
            max_j = max(arr[i] - st1.top().first + st1.top().second,max_j);
            st1.pop();
        }
        st1.push({arr[i], max_j});
        ans = max(max_j, ans);
    }
    for (int i = maxIndex; i<n; i++) {
        int max_j = 0;
        while (!st2.empty() && arr[i]>=st2.top().first) {
            max_j = max(arr[i] - st2.top().first + st2.top().second,max_j);
            st2.pop();
        }
        st2.push({arr[i], max_j});
        ans = max(max_j, ans);
    }
    cout << ans << "\n";
}
