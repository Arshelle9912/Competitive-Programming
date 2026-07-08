#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        string L, R;
        cin >> L >> R;
        int n = L.size();
        static int dp[12][2][2];
        const int INF = 1e9;
        for(int tL = 0; tL < 2; tL++)
            for(int tR = 0; tR < 2; tR++)
                dp[n][tL][tR] = 0;

        for(int i = n - 1; i >= 0; i--) {
            int l = L[i] - '0';
            int r = R[i] - '0';
            for(int tL = 0; tL < 2; tL++) {
                for(int tR = 0; tR < 2; tR++) {
                    int best = INF;
                    int low  = tL ? l : 0;
                    int high = tR ? r : 9;
                    for(int d = low; d <= high; d++) {
                        int cost = (d == l) + (d == r);
                        int ntL  = tL && (d == l);
                        int ntR  = tR && (d == r);
                        best = min(best, cost + dp[i+1][ntL][ntR]);
                    }
                    dp[i][tL][tR] = best;
                }
            }
        }
        cout << dp[0][1][1] << "\n";
    }
}