#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w, n;
        cin >> w >> h >> n;
        vector<int> heights(n+2);
        vector<int> width(n+2);
        heights[0] = 0;
        heights[n+1] = h+1;
        width[0] = 0;
        width[n+1] = w+1;
        for (int i = 1; i<n+1; i++) {
            cin >> width[i] >> heights[i];
        }
        sort(heights.begin(), heights.end());
        sort(width.begin(), width.end());
        int maxH(INT_MIN), maxW(INT_MIN);
        for (int i = 1; i<n+2; i++) {
            maxH = max(heights[i]-heights[i-1]-1, maxH);
            maxW = max(width[i]-width[i-1]-1, maxW);
        }
        cout << 1LL * maxH * maxW << "\n";
    }
}