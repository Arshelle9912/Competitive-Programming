#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> leftover;
    vector<pair<int,int>> same;
    vector<pair<int,int>> diff;
    vector<pair<int,int>> flask;
    for (int i = 0; i < n; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        if (num1 == num2) same.push_back({num1, i+1});
        else diff.push_back({min(num1, num2), i+1});
    }
    for (int i = 0; i < m; i++) {
        int num1;
        cin >> num1;
        flask.push_back({num1, i});
    }
    sort(flask.begin(), flask.end());
    sort(diff.begin(), diff.end());
    sort(same.begin(), same.end());
    vector<int> ans(m, -1);
    int ind1 = 0, ind2 = 0, ind3 = 0;
    int sz1 = same.size(), sz2 = diff.size();
    int prev = -1;
    while (ind2 < m) {
        int d = flask[ind2].first;
        vector<int> need;
        while (ind2 < m && flask[ind2].first == d) {
            need.push_back(flask[ind2].second);
            ind2++;
        }
        vector<int> currSame, currDiff;
        if (prev != d-1) leftover.clear();
        while (ind1 < sz1 && same[ind1].first < d) ind1++;
        while (ind1 < sz1 && same[ind1].first == d) {
            currSame.push_back(same[ind1].second);
            ind1++;
        }
        while (ind3 < sz2 && diff[ind3].first < d-1) ind3++;
        if (prev != d-1) {
            while (ind3 < sz2 && diff[ind3].first == d-1) {
                leftover.push_back(diff[ind3].second);
                ind3++;
            }
        }
        while (ind3 < sz2 && diff[ind3].first == d) {
            currDiff.push_back(diff[ind3].second);
            ind3++;
        }
        int ptr = 0;
        while (ptr < (int)need.size() && !leftover.empty()) {
            ans[need[ptr]] = leftover.back();
            leftover.pop_back();
            ptr++;
        }
        while (ptr < (int)need.size() && !currSame.empty()) {
            ans[need[ptr]] = currSame.back();
            currSame.pop_back();
            ptr++;
        }
        while (ptr < (int)need.size() && !currDiff.empty()) {
            ans[need[ptr]] = currDiff.back();
            currDiff.pop_back();
            ptr++;
        }
        if (ptr < (int)need.size()) {
            cout << "impossible\n";
            return 0;
        }
        leftover = currDiff;
        prev = d;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}