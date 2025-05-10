#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, result;
    long long count;
    cin >> t;
    for (int i = 0; i<t; i++) {
        cin >> n;
        int low = 1, high = n;
        while (low <= high) {
            count = 0;
            vector<int> ans;
            long long mid = (low + high)/2;
            cout << "? " << low << " " << mid << endl;
            for (int j = low; j<=mid; j++) {
                int x;
                cin >> x;
                ans.push_back(x);
            }
            for (auto it : ans) {
                if (it >= low && it <= mid) {
                    count++;
                }
            }
            if (count & 1) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << result << endl;
    }
}