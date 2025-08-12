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
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            s.push(arr[i]);
        }
        int sum = 0;
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            if (curr == 0)
            {
                sum++;
                continue;
            }
            sum += curr;
        }
        cout << sum << "\n";
    }
}