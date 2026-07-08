#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> problems(n, -1);
        for (int i = 0; i<m; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            --num1;
            --num2;
            if (num2<num1) swap(num1, num2);
            if (problems[num2]<num1) problems[num2] = num1;
        }
        int left = 0;
        long long ans = 0;
        for (int i = 0; i<n; i++) {
            left = max(left, problems[i]+1);
            ans += (i-left+1);
        }
        cout << ans << "\n";
    }
}