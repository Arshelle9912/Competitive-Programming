#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, c;
    cin >> n >> k >> c;
    map<string, int> mp;
    map<int, string> mp2;
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
        mp2[i] = s;
    }
    vector<int> dislike(k);
    for (int i = 0; i<k; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        dislike[i] = (1<<mp[s1])|(1<<mp[s2]);
    }
    vector<int> subsets;
    for (int mask = 0; mask<(1<<n); mask++) {
        int count = 0;
        bool check = true;
        for (int i = 0; i<n; i++) {
            if (mask&(1<<i)) count++;
            if (count>c) {check = false; break;}
        }
        if (!check) continue;
        for (int i = 0; i<k; i++) {
            if ((mask&dislike[i])==dislike[i]) {check = false; break;}
        }
        if (check) subsets.push_back(mask);
    }
    vector<int> dp(1<<n, 1e9), par(1<<n, -1), used(1<<n, -1);
    dp[0] = 0;
    for (int mask = 0; mask<(1<<n); mask++) {
        if (dp[mask]==1e9) continue;
        for (int i = 0; i<subsets.size(); i++) {
            if ((mask&subsets[i])==0) {
                int nmask = mask|subsets[i];
                if (1+dp[mask]<dp[nmask]) {
                    dp[nmask] = 1+dp[mask];
                    par[nmask] = mask;
                    used[nmask] = subsets[i];
                }
            }
        }
    }
    printf("%d\n", dp[(1<<n)-1]);
    int mask = (1<<n)-1;
    while (mask!=0) {
        int curr = used[mask];
        for (int i = 0; i<n; i++) {
            if (curr&(1<<i)) {
                printf("%s ", mp2[i].c_str());
            }
        }
        printf("\n");
        mask = par[mask];
    }
}