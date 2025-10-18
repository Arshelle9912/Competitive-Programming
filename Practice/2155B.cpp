#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == n * n - 1)
        {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        int count = k;
        vector<vector<char>> adj(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (count > 0)
                {
                    adj[i][j] = 'U';
                    count--;
                }
                else if (i == n - 1 && j == n - 1)
                {
                    adj[i][j] = 'L';
                }
                else if (i == n - 1)
                {
                    adj[i][j] = 'R';
                }
                else
                {
                    adj[i][j] = 'D';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j];
            }
            cout << "\n";
        }
    }
}