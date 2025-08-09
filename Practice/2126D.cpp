#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, start;
        cin >> n >> start;
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int l, r, real;
            cin >> l >> r >> real;
            arr.emplace_back(real, l, r);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (get<0>(arr[i]) > start && start >= get<1>(arr[i]))
            {
                start = get<0>(arr[i]);
            }
        }
        cout << start << "\n";
    }
}