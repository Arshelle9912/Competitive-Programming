#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long low = 1; 
        long long high = n;
        long long origHalf;
        long long updatedHalf;
        long long totalOrig = n*(n+1)/2;
        long long totalUpdated;
        cout << 2 << " " << low << " " << high << "\n";
        cin >> totalUpdated;
        long long len = totalUpdated - totalOrig;
        if (len<=0) {
            cout << "! 1 1" << endl;
            continue;
        }
        while (low<high) {
            long long mid = (low+high)/2;
            cout << 1 << " " << 1 << " " << mid << "\n";
            cin >> origHalf;
            cout << 2 << " " << 1 << " " << mid << "\n";
            cin >> updatedHalf;
            int diff = updatedHalf - origHalf;
            if (diff>0) high = mid;
            else low = mid+1;
        }
        int L = low;
        int R = L + (int) len -1;
        cout << "! " << L << " " << R << endl;
    }
}