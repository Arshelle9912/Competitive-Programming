#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        int k = 0;
        long long need = x + 1;
        while ((1LL << k) < need)
            ++k;
        cout << (2 * k + 1) << '\n';
    }
}