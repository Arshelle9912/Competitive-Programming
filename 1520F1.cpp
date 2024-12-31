#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int n, int k) {
    int low = 1, high = n, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "? " << low << " " << mid << endl;
        int sum;
        cin >> sum;
        if (mid - low - k + 1 >= sum) {
            ans = mid;
            high = mid - 1;
        } else {
            k -= (mid - low + 1 - sum);
            low = mid + 1;
        }
    }
    cout << "! " + to_string(ans) << endl;
    return ans;
}
int main() {
    int n, t, k;
    cin >> n >> t;
    cin >> k;
    binarySearch(n, k);
    return 0;
}