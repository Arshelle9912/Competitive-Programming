#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sparsetable;
int LOG = 31;
void sparse_construction(int n, vector<int> a) {
    sparsetable.assign(n+1, vector<int> (LOG));
    for (int i = 0; i<n; i++) {
        sparsetable[i][0] = a[i];
    }
    for (int j = 1; j<LOG; j++) {
        for (int i = 0; i+(1<<j) <= n; i++) {
            sparsetable[i][j] = sparsetable[i][j-1] & sparsetable[i + (1<<(j-1))][j-1];
        }
    }
}
vector<int> logtable(int n) {
    vector<int> log(n+1);
    log[1] = 0;
    for (int i = 2; i<=n; i++) {
        log[i] = log[i/2]+1;
    }
    return log;
}
int query(vector<int>& lg, int l, int r) {
    int len = r-l+1;
    int j = lg[len];
    return sparsetable[l][j] & sparsetable[r-(1<<(j))+1][j]; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<int> lg = logtable(n);
        sparse_construction(n, arr);
        int q;
        cin >> q;
        for (int i = 0; i<q; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            num1--;
            int low = num1;
            int high = n-1;
            int ans = -1;
            while (low<=high) {
                int mid = (low+high)/2;
                if (query(lg, num1, mid)>=num2) {
                    ans = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            cout << (ans == -1 ? -1 : ans + 1) << " ";
        }
        cout << "\n";
    }
}