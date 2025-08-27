#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (n % 2 == 0)
        {
            if (a > b)
            {
                if (a % 2 == 0 && b % 2 == 0)
                {
                    cout << "YES" << "\n";
                    continue;
                }
                else
                {
                    cout << "NO" << "\n";
                    continue;
                }
            }
            else
            {
                if (b % 2 == 0)
                {
                    cout << "YES" << "\n";
                }
                else
                {
                    cout << "NO" << "\n";
                }
            }
        }
        else
        {
            if (a > b)
            {
                if (a % 2 != 0 && b % 2 != 0)
                {
                    cout << "YES" << "\n";
                }
                else
                {
                    cout << "NO" << "\n";
                }
            }
            else
            {
                if (b % 2 != 0)
                {
                    cout << "YES" << "\n";
                }
                else
                {
                    cout << "NO" << "\n";
                }
            }
        }
    }
}