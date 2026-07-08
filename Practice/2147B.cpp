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
        vector<int> arr(2 * n + 1, 0);
        int lastIndex = 1;
        for (int i = n; i > 0; i--)
        {
            while (lastIndex <= 2 * n && arr[lastIndex] != 0)
            {
                lastIndex++;
            }
            arr[lastIndex] = i;
            int index = lastIndex;
            while (index <= 2 * n)
            {
                index += i;
                if (arr[index] == 0)
                {
                    arr[index] = i;
                    break;
                }
            }
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}