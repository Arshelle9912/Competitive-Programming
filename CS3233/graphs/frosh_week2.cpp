#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> len1(n);
    vector<int> len2(m);
    for (int i = 0; i<n; i++) {
        cin >> len1[i];
    }
    for (int i = 0; i<m; i++) {
        cin >> len2[i];
    }
    sort(len1.begin(), len1.end());
    sort(len2.begin(), len2.end());
    int pointer1 = n-1;
    int pointer2 = m-1;
    int ans = 0;
    while (pointer1>=0 && pointer2>=0) {
        if (len1[pointer1]<=len2[pointer2]) {
            pointer1--;
            pointer2--;
            ans++;
        } else {
            pointer1--;
        }
    }
    printf("%d\n", ans);
}