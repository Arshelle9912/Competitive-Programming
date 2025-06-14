#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    vector<int> order(n);
    for (int i = 0; i<n; i++) {
        cout << 1 << endl;
        cin >> order[i];
    }
    int low(1), high = m, count(0), query;
    while (low<=high) {
        int mid = (low) + (high-low)/2;
        cout << mid << endl;
        cin >> query;
        query = order[count%n] * query;
        if (query==1) {
            low = mid+1;
        } else if (query==-1) {
            high = mid-1;
        } else {
            cout << mid << endl;
            return 0;
        }
        count ++;
    }
}