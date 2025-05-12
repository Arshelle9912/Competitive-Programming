#include <bits/stdc++.h>
using namespace std;

vector<int> checker(vector<int> &, int);
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int low = 1, high = (n+1)/2-1, ans(0);
    sort(arr.begin(), arr.end());
    vector<int> result = arr;
    while (low <= high) {
        int mid = low + (high-low)/2;
        auto check = checker(arr, mid);
        if (!check.empty()) {
            ans = mid;
            result = move(check);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    for (int x: result) {
        cout << x << " ";
    }
}

vector<int> checker(vector<int>& arr, int mid) {
    int n = arr.size();
    int count(0);
    vector<int> result(n);
    int i(n-1), j(mid-1);
    for (int index = 0; index<n; index++) {
        if ((index%2==0) || j<0) {
            result[index] = arr[i--];
        } else {
            result[index] = arr[j--];
        }
    }
    for (int p = 1; p + 1 < n; p += 2) {
        if (result[p] < result[p-1] && result[p] < result[p+1])
            count++;
    }
    if (count==mid) {
        return result;
    }
    return vector<int>();
}