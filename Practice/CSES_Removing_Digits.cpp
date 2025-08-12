#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int t = i;
        while (t)
        {
            int d = t % 10;
            t /= 10;
            if (d)
            {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
}