#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int m = b.length();
    int n = a.length();
    int sumC(0);
    int sumB(0);
    long long ans(0);
    for (int i = 0; i<m; i++) {
        sumC += (a[i]-'0');
        sumB += (b[i]-'0');
    }
    ans+=(sumC+sumB)%2==0;
    for (int i = m; i<n; i++) {
        sumC+=(a[i]-a[i-m]);
        ans+=(sumC+sumB)%2==0;
    }
    cout << ans << endl;
}