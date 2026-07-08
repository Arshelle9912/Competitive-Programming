#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> stock(n + 2, 0);
        long long matches = 0;
        for (int x : arr) {
            if (stock[x - 1] > 0) {  
                --stock[x - 1];
                ++matches;
            } else {
                ++stock[x];        
            }
        }
        cout << matches << "\n";    
    }
}