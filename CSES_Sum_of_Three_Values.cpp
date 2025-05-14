#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int> > arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i<n; i++) {
        int remaining = k - arr[i].first;
        int low = i+1, high = n-1;
        while (low < high) {
            if ((arr[low].first+arr[high].first)>remaining) {
                high--;
            } else if ((arr[low].first+arr[high].first)<remaining) {
                low++;
            } else {
                cout << arr[i].second + 1 << " " << arr[low].second + 1 << " " << arr[high].second + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}