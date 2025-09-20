#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum += arr[i];
            }
            else
            {
                sum -= arr[i];
            }
        }
        vector<long long> suff(n);
        vector<long long> pref(n);
        const long long NEG = (long long)-2e18;
        long long bestodd = NEG;
        for (int i = 0; i < n; i++)
        {
            pref[i] = bestodd;
            if (i % 2 == 0)
            {
                bestodd = max(bestodd, -2 * arr[i] - i);
            }
        }
        bestodd = NEG;
        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = bestodd;
            if (i % 2 == 0)
            {
                bestodd = max(bestodd, -2 * arr[i] + i);
            }
        }

        long long bestgain = 0;
        for (int i = 1; i < n; i += 2)
        {
            if (pref[i] != NEG)
            {
                bestgain = max(bestgain, 2 * arr[i] + i + pref[i]);
            }
            if (suff[i] != NEG)
            {
                bestgain = max(bestgain, 2 * arr[i] - i + suff[i]);
            }
        }
        long long bestSame = 0;
        if (n >= 3)
        {
            int lastEven = ((n - 1) % 2 == 0) ? (n - 1) : (n - 2);
            if (lastEven >= 2)
            {
                bestSame = max(bestSame, (long long)lastEven);
            }
        }
        if (n >= 4 || (n >= 2 && (n - 1) % 2 == 1))
        {
            int lastOdd = ((n - 1) % 2 == 1) ? (n - 1) : (n - 2);
            if (lastOdd >= 3)
            {
                bestSame = max(bestSame, (long long)(lastOdd - 1));
            }
        }
        bestgain = max(bestgain, bestSame);
        cout << sum + bestgain << "\n";
    }
}