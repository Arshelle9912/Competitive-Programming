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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long count(0);
        for (int i = 0; i < n - 2; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                count += (arr[i] - arr[i + 1]);
                arr[i] = arr[i + 1];
            }
            if (arr[i] + arr[i + 2] > arr[i + 1])
            {
                int diff = (arr[i] + arr[i + 2] - arr[i + 1]);
                count += diff;
                arr[i + 2] -= diff;
            }
        }
        if (n % 2 == 0)
        {
            if (arr[n - 2] > arr[n - 1])
            {
                count += ((arr[n - 2] - arr[n - 1]));
            }
        }
        else
        {
            if (arr[n - 1] > arr[n - 2])
            {
                count += ((arr[n - 1] - arr[n - 2]));
            }
            if (n - 3 >= 0 && (arr[n - 1] + arr[n - 3] > arr[n - 2]))
            {
                int diff = (arr[n - 1] + arr[n - 3] - arr[n - 2]);
                count += diff;
            }
        }
        cout << count << "\n";
    }
}