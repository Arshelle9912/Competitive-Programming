#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> map;
        for (int i = 0; i<2*n; i++) {
            int temp;
            cin >> temp;
            map[temp]++;
        }
        int countEvenOdd(0), countEvenEven(0), countOdd(0);
        for (auto &it : map) {
            if (it.second%2==0) {
                if ((it.second/2) % 2 == 0) {
                    countEvenEven++;
                } else {
                    countEvenOdd++;
                }
            } else {
                countOdd++;
            }
        }
        int ans(0);
        ans += 2*countEvenOdd;
        if (countEvenEven%2!=0) {
            if (countOdd<2) {
                ans += 2*(countEvenEven-1);
            } else {
                ans += 2*countEvenEven;
            }
        } else {
            ans+=2*countEvenEven;
        }
        ans+=countOdd;
        cout << ans << "\n";
    }
}