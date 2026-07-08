#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long rating, threshold, delta;
        int m;
        cin >> rating >> threshold >> delta >> m;
        string rounds;
        cin >> rounds;
        long long low = rating, high = rating;
        int ratedCount = 0;

        for (char r : rounds) {
            if (r == '1') {
                ++ratedCount;
                low = max(0LL, low - delta);
                high += delta;
            } else {
                if (low < threshold) {
                    ++ratedCount;
                    long long nlow = max(0LL, low - delta);
                    long long nhigh = min(high, threshold - 1) + delta;
                    low = nlow;
                    high = nhigh;
                }
            }
        }
        cout << ratedCount << "\n";
    }
    return 0;
}