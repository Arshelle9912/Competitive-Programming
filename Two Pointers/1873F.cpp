#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        long long n, k;
        cin >> n >> k;
        vector<long long> fruits(n);
        vector<long long> heights(n);
        for (int i = 0; i<n; i++) {
            cin >> fruits[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> heights[i];
        }
        int result = 0, left(0);
        long long count(0);
        for (int i = 0; i<n; i++) {
            if (i>0 && heights[i-1]%heights[i]!=0) {
                left = i;
                count = 0;
            }
            count += fruits[i];
            while (count>k) {
                count-=fruits[left];
                left++;
            }
            result = max(result, i - left + 1);
        }
        cout << result << endl;
    }
}