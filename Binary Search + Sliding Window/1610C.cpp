#include <bits/stdc++.h>
using namespace std;

bool checker(vector<vector<int> >, int, int);
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<vector<int> > arr(n, vector<int>(2));
        for (int j = 0; j<n; j++) {
            cin >> arr[j][0] >> arr[j][1];
        }
        int low = 0, high = 1e5 * 2, mid, result;
        while (low <= high) {
            mid = (low + high)/2;
            if (checker(arr, mid, n)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << result << endl;
    }
}

bool checker(vector<vector<int> > arr, int mid, int n) {
    int count(0);
    for (int i = 0; i<n; i++) {
        if (arr[i][1]>=count && arr[i][0]>=mid - count - 1) {
            count++;
        }
    }
    if (count>=mid) {
        return true;
    }
    return false;
}