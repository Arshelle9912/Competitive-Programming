#include <bits/stdc++.h>
using namespace std;
tuple<long long, long long, long long> gcd(long long a, long long b)
{
    if (b == 0)
        return {a, 1, 0};
    auto [g, x1, y1] = gcd(b, a % b);
    long long x = y1;
    long long y = x1 - (a / b) * y1;
    return {g, x, y};
}

long long modinv(long long a, long long m)
{
    a %= m;
    if (a < 0)
        a += m;
    auto [g, x, y] = gcd(a, m);
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<long long> result(n);
        if (k % 2 != 0)
        {
            for (long long i = 0; i < n; i++)
            {
                if (arr[i] % 2 != 0)
                {
                    result[i] = arr[i] + k;
                }
                else
                {
                    result[i] = arr[i];
                }
                cout << result[i] << " ";
            }
            cout << "\n";
            continue;
        }
        long long m = k + 1;
        long long invk = modinv(k % m, m);
        for (int i = 0; i < n; ++i)
        {
            long long ai_mod = arr[i] % m;
            if (ai_mod < 0)
                ai_mod += m;
            long long xi = ((m - ai_mod) % m) * invk % m;
            arr[i] += xi * k;
        }
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
}