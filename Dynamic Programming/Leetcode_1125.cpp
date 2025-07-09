#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
vector<int> f(int index, int n, int mask, vector<int>& masks, int m) {
    if (mask==((1<<m)-1)) {
        return {};
    }
    if (index == n) {
        return vector<int>{-1};
    }
    if (!dp[index][mask].empty()) {
        return dp[index][mask];
    }
    vector<int> skip = f(index+1, n, mask, masks, m);
    vector<int> pick = f(index+1, n, mask | (masks[index]), masks, m);
    if (!(pick.size()==1 && pick[0]==-1)) {
        pick.insert(pick.begin(), index);
    }
    bool sb = skip.size()==1 && skip[0]==-1;
    bool pb = pick.size()==1 && pick[0]==-1;
    vector<int> best;
    if (sb && pb) {
        best = vector<int>{-1};
    }
    else if (sb) {
        best = pick;
    }
    else if (pb) {
        best = skip;
    }
    else {
        best = (pick.size() < skip.size() ? pick : skip);
    }
    return dp[index][mask] = best;
}
vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    map<string, int> mp;
    for (int i = 0; i<req_skills.size(); i++) {
        mp[req_skills[i]] = i;
    }
    vector<int> masks(people.size());
    for (int i = 0; i<people.size(); i++) {
        for (string s : people[i]) {
            masks[i] |= (1<<(mp[s]));
        }
    }
    dp.assign(people.size()+1, vector<vector<int>> (1<<(req_skills.size())));
    return f(0, people.size(), 0, masks, req_skills.size());
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> requiredSkills(n);
    for (int i = 0; i<n; i++) {
        cin >> requiredSkills[i];
    }
    vector<vector<string>> people(m);
    for (int i = 0; i<m; i++) {
        int skills;
        cin >> skills;
        for (int j = 0; j<skills; j++) {
            string temp;
            cin >> temp;
            people[i].push_back(temp);
        }
    }
    vector<int> ans = smallestSufficientTeam(requiredSkills, people);
    for (int i : ans) {
        cout << i << "\n";
    }
}