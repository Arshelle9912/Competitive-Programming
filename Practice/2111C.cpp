#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long ans(LLONG_MAX);
        long long left(0), right(0);
        while (left < n)
        {
            while (right < n && arr[right] == arr[left])
            {
                right++;
            }
            right--;
            ans = min(left * arr[left] + (n - right - 1) * arr[right], ans);
            left++;
            if (right < left)
            {
                right = left;
            }
        }
        cout << ans << "\n";
    }
}