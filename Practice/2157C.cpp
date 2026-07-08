#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<vector<int>> queries(q, vector<int> (3));
        for (int i = 0; i<q; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            queries[i][0] = c;
            queries[i][1] = l;
            queries[i][2] = r;
        }
        vector<int> softassign(n+1, INT_MAX);
        for (vector<int> que : queries) {
            for (int l = que[1]; l<=que[2]; l++) {
                if (que[0]==1) {
                    if (softassign[l]==0) {
                        softassign[l] = 2;
                    } else if (softassign[l] == INT_MAX) {
                        softassign[l] = 1;
                    }
                } else if (que[0]==2) {
                    if (softassign[l]==1) {
                        softassign[l]=2;
                    } else if (softassign[l]==INT_MAX) {
                        softassign[l] = 0;
                    }
                }
            }
        }
        vector<int> hardassign(n+1, INT_MAX);
        for (int i = 1; i<=n; i++) {
            if (softassign[i]==1) {
                hardassign[i] = k;
            } else if (softassign[i]==2) {
                hardassign[i] = k+1;
            }
        }
        vector<pair<int, int>> quer;
        for (vector<int> v : queries) {
            if (v[0]==2) {
                quer.push_back({v[2], v[1]});
            }
        }
        sort(quer.begin(), quer.end());
        for (int i = 0; i<k; i++) {
            for (pair<int, int> ve : quer) {
                bool check = false;
                for (int j = ve.first; j>=ve.second; j--) {
                    if (hardassign[j]==i) check = true;
                }
                if (!check) {
                    for (int j = ve.first; j>=ve.second; j--) {
                        if (hardassign[j]==INT_MAX) {
                            hardassign[j] = i;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i<=n; i++) {
            if (hardassign[i]==INT_MAX) hardassign[i] = k+1;
            cout << hardassign[i] << " ";
        }
        cout << "\n";
    }
}