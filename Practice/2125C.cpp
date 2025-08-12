#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> num = {2, 3, 5, 7};
    vector<int> pair = {6, 10, 14, 15, 21, 35};
    vector<int> triple = {30, 42, 70, 105};
    vector<int> quad = {210};
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long count(0);
        for (int i : num)
        {
            count += r / i;
            count -= (l - 1) / i;
        }
        for (int i : pair)
        {
            count -= r / i;
            count += (l - 1) / i;
        }
        for (int i : triple)
        {
            count += r / i;
            count -= (l - 1) / i;
        }
        for (int i : quad)
        {
            count -= r / i;
            count += (l - 1) / i;
        }
        cout << r - l + 1 - count << "\n";
    }
}