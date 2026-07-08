#include <bits/stdc++.h>
using namespace std;
bool backtrack(vector<int>& friendMask, vector<int>& dp, int index, int mask, int n) {
    if (mask==((1<<n)-1)) return true;
    if (dp[mask] != -1) return dp[mask];
    vector<int> freeIndices;
    for (int i = 0; i<n; i++) {
        if (!(mask&(1<<i))) freeIndices.push_back(i);
    }
    for (int i = 0; i<freeIndices.size(); i++) {
        for (int j = i+1; j<freeIndices.size(); j++) {
            if (freeIndices[i] == index || freeIndices[j] == index) continue;
            if ((friendMask[index] & (1<<freeIndices[i])) &&
                (friendMask[index] & (1<<freeIndices[j])) &&
                (friendMask[freeIndices[i]] & (1<<freeIndices[j]))) {
                int nmask = mask|((1<<freeIndices[i]));
                nmask |= (1<<freeIndices[j]);
                nmask |= (1<<index);
                if (nmask == ((1<<n)-1)) return dp[mask] = true;
                int nextUnused;
                for (int i = index+1; i<n; i++) {
                    if (!(nmask&(1<<i))) {
                        nextUnused = i;
                        break;
                    }
                }
                if (backtrack(friendMask, dp, nextUnused, nmask, n)) return dp[mask] = true;
            }
        }
    }
    return dp[mask] = false;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;
        map<string, int> mp;
        int count = 0;
        vector<pair<string, string>> pairs(n);
        for (int i = 0; i<n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!mp.count(s1)) {mp[s1] = count; count++;}
            if (!mp.count(s2)) {mp[s2]=count; count++;}
            pairs[i] = {s1, s2};
        }
        vector<int> friendMask(count);
        for (int i = 0; i<n; i++) {
            string s1 = pairs[i].first;
            string s2 = pairs[i].second;
            friendMask[mp[s1]] |= (1<<mp[s2]);
            friendMask[mp[s2]] |= (1<<mp[s1]);
        }
        if (count % 3 != 0) {
            cout << "impossible\n";
            continue;
        }
        vector<int> dp(1<<count, -1);
        if (backtrack(friendMask, dp, 0, 0, count)) {
            printf("possible\n");
        } else {
            printf("impossible\n");
        }
    }
}