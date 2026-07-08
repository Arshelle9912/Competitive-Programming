#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<vector<long long>> grid(n, vector<long long> (n));
    for (long long i = 0; i<n; i++) {
        for (long long j = 0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    bool check = true;
    bool one = true;
    vector<vector<long long>> midGrid1(n, vector<long long> (n));
    vector<vector<long long>> midGrid2(n, vector<long long> (n));
    for (long long i = 0; i<n; i++) {
        for (long long j = 0; j<i; j++) {
            if ((grid[i][j]-grid[j][i])%2!=0) {
                check = false;
            }
            else if (abs(grid[i][j])==abs(grid[j][i])) continue;
            else if (grid[i][j]<grid[j][i]) {
                long long diff = grid[j][i]-grid[i][j];
                midGrid1[i][j] = -diff/2;
                midGrid1[j][i] = diff/2;
                one = false;
            }
            else if (grid[i][j]>grid[j][i]) {
                long long diff = grid[i][j]-grid[j][i];
                midGrid1[i][j] = diff/2;
                midGrid1[j][i] = -diff/2;
                one = false;
            }
        }
    }
    if (!check) {
        printf("-1\n");
        return 0;
    }
    if (one) {
        printf("1\n");
        for (long long i = 0; i<n; i++) {
            for (long long j = 0; j<n; j++) {
                printf("%lld ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("2\n");
        for (long long i = 0; i<n; i++) {
            for (long long j = 0; j<n; j++) {
                midGrid2[i][j] = (grid[i][j]-midGrid1[i][j]);
                printf("%lld ", midGrid1[i][j]);
            }
            printf("\n");
        }
        for (long long i = 0; i<n; i++) {
            for (long long j = 0; j<n; j++) {
                printf("%lld ", midGrid2[i][j]);
            }
            printf("\n");
        }
    }
}