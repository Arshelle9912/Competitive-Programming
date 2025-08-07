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
        --k;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        int val = heights[k];
        sort(heights.begin(), heights.end());
        int maximum = heights[n - 1];
        int index;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] == val)
            {
                index = i;
            }
        }
        bool check = true;
        int time(0);
        while (index != n - 1)
        {
            while (index < n - 1 && heights[index] == heights[index + 1])
            {
                index++;
            }
            if (index == n - 1)
            {
                break;
            }
            if (heights[index] >= heights[index + 1] - heights[index] + time)
            {
                time += heights[index + 1] - heights[index];
                index++;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}