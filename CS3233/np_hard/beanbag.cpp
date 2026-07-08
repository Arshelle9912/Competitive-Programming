#include <bits/stdc++.h>
using namespace std;
int main() {
    int b;
    cin >> b;
    vector<int> req(b);
    int totalReq = 0;
    for (int i = 0; i<b; i++) {
        cin >> req[i];
        totalReq+=req[i];
    }
    int t;
    cin >> t;
    vector<int> farmerMask(t);
    for (int i = 0; i<t; i++) {
        int num;
        cin >> num;
        int mask = 0;
        for (int j = 0; j<num; j++) {
            int fr;
            cin >> fr;
            fr--;
            mask|=(1<<fr);
        }
        farmerMask[i] = mask;
    }
    int ans = INT_MAX;
    auto cost = [&] (int mask) {
        int tot = 0;
        for (int ind = 0; ind<b; ind++) {
            if (mask&(1<<ind)) tot+=req[ind];
        }
        return tot;
    };
    for (int mask = 0; mask<(1<<b); mask++) {
        int total = cost(mask);
        if (total>ans) continue;
        bool check = true;
        for (int i = 0; i<t; i++) {
            if ((farmerMask[i]&mask)==0) {
                check = false; 
                break;
            }
        }
        if (check) ans = min(total, ans);
    }
    printf("%d\n", totalReq-ans);
}