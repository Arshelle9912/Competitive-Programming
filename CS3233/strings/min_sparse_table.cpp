#include <bits/stdc++.h>
using namespace std;
vector<int> logtable;
vector<vector<int>> sparsetable;
void build_logs(int n) {
    logtable.assign(n+1, 0);
    for (int i = 2; i<=n; i++) {
        logtable[i] = logtable[i/2]+1;
    }
}
void create_table(int n, vector<int>& arr) {
    sparsetable.assign(logtable[n]+1, vector<int> (n, 1e9));
    for (int i = 0; i<n; i++) {
        sparsetable[0][i] = arr[i];
    }
    for (int i = 1; i<logtable[n]+1; i++) {
        for (int j = 0; j<n; j++) {
            if (j+(1<<(i-1))<n) {
                sparsetable[i][j] = min(sparsetable[i-1][j], sparsetable[i-1][j+(1<<(i-1))]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    build_logs(n);
    create_table(n, arr);
    for (int i = 0; i<q; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        num1--;
        num2--;
        int len = num2-num1+1;
        int start = num1;
        int ans = 1e9;
        for (int i = logtable[len]; i>=0; i--) {
            if (len&(1<<i)) {
                ans = min(ans, (sparsetable[i][start]));
                start+=(1<<i);
            }
        }
        printf("%d\n", ans);
    }
}