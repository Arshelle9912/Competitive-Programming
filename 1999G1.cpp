#include <iostream>
using namespace std;

int main() {
    int n;
    int result = 999;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int low = 2, high = 999, ans;
        while (low <= high) {
            int mid = (low + high)/2;
            cout << "? " << 1 << " " << mid << endl;
            cin >> ans;
            if (ans > mid) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << result << endl;
    }
}