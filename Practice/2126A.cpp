#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int minimum = 9;
        for (char c : s)
        {
            minimum = min(minimum, c - '0');
        }
        cout << minimum << "\n";
    }
}