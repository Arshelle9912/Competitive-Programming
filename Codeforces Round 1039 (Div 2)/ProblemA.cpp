#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        multiset<long long> arr;
        for (int i = 0; i < n; i++) {
            long long w;
            cin >> w;
            arr.insert(w);
        }
        int coins = 0;
        for (int step = 0; step < n; step++) {
            auto it = arr.upper_bound(c);
            bool paid = false;
            if (it == arr.begin()) {
                it = arr.begin();
                paid = true;
            } else {
                --it;
            }
            arr.erase(it);
            if (paid) 
                ++coins;

            vector<long long> snap(arr.begin(), arr.end());
            arr.clear();
            for (long long w : snap) {
                arr.insert(w * 2);
            }
        }
        cout << coins << "\n";
    }
    return 0;
}
