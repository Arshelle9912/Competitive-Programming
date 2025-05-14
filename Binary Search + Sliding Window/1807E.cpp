#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int n, vector<int>& pieces) {
    int low = 1, high = n, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "? " << mid - low + 1 << " ";
        for (int i = low; i <= mid; ++i) {
            cout << i << " ";
        }
        cout << endl;
        int sum;
        cin >> sum;
        int l = low > 1 ? pieces[low - 2] : 0;
        if (pieces[mid - 1] - l < sum) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "! " << ans << endl;
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, count = 0;
        cin >> n;
        vector<int> pieces;
        
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            count += temp;
            pieces.push_back(count);
        }
        
        binarySearch(n, pieces);
    }
    
    return 0;
}
