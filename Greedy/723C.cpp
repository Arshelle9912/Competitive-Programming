#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), freq(m+1), changes;
    int changeSum(0);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++) {
        if (arr[i]>m) {
            changes.push_back(i);
        } else if (freq[arr[i]]==n/m) {
            changes.push_back(i);
        } else {
            freq[arr[i]]++;
        }
    }
    for (int i = 1; i<=m; i++) {
        while (freq[i]<n/m) {
            arr[changes.back()] = i;
            changeSum++;
            changes.pop_back();
            freq[i]++;
        }
    }
    cout << n/m << " " << changeSum << "\n";
    for (int x:arr) {
        cout << x << " ";
    }
}