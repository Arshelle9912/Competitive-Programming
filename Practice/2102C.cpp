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
        vector<vector<long long>> arr(n, vector<long long>(n, -1));
        int x = (n % 2 ? n / 2 : n / 2 - 1);
        int y = (n % 2 ? n / 2 : n / 2 - 1);
        arr[x][y] = 0;
        int count = 1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int len = 1;
        int dir = 0;
        while (count < n * n)
        {
            for (int rep = 0; rep < 2 && count < n * n; rep++)
            {
                for (int step = 0; step < len && count < n * n; step++)
                {
                    x += dx[dir];
                    y += dy[dir];
                    if (0 <= x && x < n && 0 <= y && y < n && arr[x][y] == -1)
                    {
                        arr[x][y] = count++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            ++len;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
}