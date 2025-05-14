#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int low = 1, high = n;
    int ans;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> value(3);
        if (mid - 1 > 0) {
            cout << "? " << mid - 1 << endl;
            cin >> value[0];
        } else {
            value[0] = INT_MAX;
        }
        cout << "? " << mid << endl;
        cin >> value[1];
        if (mid + 1 <= n) {
            cout << "? " << mid + 1 << endl;
            cin >> value[2];
        } else {
            value[2] = INT_MAX;
        }

        if ((value[1]<value[2]) and (value[1]<value[0])) {
            ans = mid;
            break;
        } else if ((value[1]<value[2]) and (value[1]>value[0])) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << "! " << ans;
}