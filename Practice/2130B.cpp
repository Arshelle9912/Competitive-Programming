#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int count0(0);
        int count1(0);
        int count2(0);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                count0++;
            if (temp == 1)
                count1++;
            if (temp == 2)
                count2++;
        }
        int sum = count1 + 2 * count2;
        if ((s - sum != 1 && s > sum) || (s == sum))
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < count0; i++)
            cout << 0 << " ";
        for (int i = 0; i < count2; i++)
            cout << 2 << " ";
        for (int i = 0; i < count1; i++)
            cout << 1 << " ";
        cout << "\n";
    }
}