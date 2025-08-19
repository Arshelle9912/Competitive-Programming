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
        int start;
        cin >> start;
        start = abs(start);
        int count(0);
        for (int i = 1; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (abs(temp) < start)
                count++;
        }
        if (count > n - count - 1)
        {
            if (n % 2 == 0 && count == n - count)
            {
                cout << "YES" << "\n";
                continue;
            }
            cout << "NO" << "\n";
        }
        else
            cout << "YES" << "\n";
    }
}