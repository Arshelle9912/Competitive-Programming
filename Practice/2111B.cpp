#include <bits/stdc++.h>
using namespace std;
pair<int, int> fibo(int n)
{
    int a(1), b(2);
    for (int i = 2; i <= n; i++)
    {
        swap(a, b);
        b += a;
    }
    return {a, b};
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        pair<int, int> fib = fibo(n);
        for (int i = 0; i < m; i++)
        {
            int w, l, h;
            cin >> w >> l >> h;
            vector<int> arr = {w, l, h};
            sort(arr.begin(), arr.end());
            if (fib.first <= arr[0] && fib.second <= arr[2])
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << "\n";
    }
}