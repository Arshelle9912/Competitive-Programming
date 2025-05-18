#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> arr(n);
    vector<int> remainder(m, 0);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
        remainder[arr[i]%m]++;
    }
    int index = -1;
    for (int i = 0; i<m; i++) {
        if (remainder[i]>=k) {
            cout << "Yes" << "\n";
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "No" << "\n";
        return 0;
    }
    int count(0);
    for (int i = 0; i<n; i++) {
        if (arr[i]%m==index) {
            cout << arr[i] << " ";
            count++;
            if (count>=k) {
                break;
            }
        }
    }
}