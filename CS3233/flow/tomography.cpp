#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    vector<int> r(n);
    int totalR(0), totalC(0);
    for (int i = 0; i<n; i++) {
        cin >> r[i];
        totalR+=r[i];
    }
    for (int j = 0; j<m; j++) {
        cin >> c[j];
        totalC+=c[j];
    }
    if (totalC!=totalR) {
        printf("No\n");
        return 0;
    }
    sort(r.begin(), r.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    vector<int> pref(m+1, 0);
    for (int j = 1; j <= m; j++) {
        pref[j] = pref[j - 1] + c[j - 1];
    }
    for (int k = 1; k<=n; k++) {
        int rowSum = 0;
        for (int i = 0; i<k; i++) {
            rowSum+=r[i];
        }
        int colSum = 0;
        for (int j = 0; j<m; j++) {
            colSum += min(c[j], k);
        }
        if (rowSum>colSum) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}