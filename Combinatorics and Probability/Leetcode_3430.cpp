#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long countPairs(long long L, long long R, long long k) {
    ll Lp = min(L, k);
    ll t = k - R + 1;
    ll fullRows = 0;
    if (t > 0) {
        fullRows = min(t, Lp);
    }
    ll sumA = fullRows * R;
    ll partialRows = Lp - fullRows;
    if (partialRows <= 0) {
        return sumA;
    }
    ll firstTerm = k - fullRows;
    ll lastTerm  = k - Lp + 1;
    ll sumB = partialRows * (firstTerm + lastTerm) / 2;
    return sumA + sumB;
}

long long minMaxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> Pmax(n), Nmax(n), Pmin(n), Nmin(n);
    stack<int> st;
    for (int i = 0; i<n; i++) {
        while(!st.empty() && nums[st.top()]<=nums[i]) {
            st.pop();
        }
        Pmax[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n-1; i>=0; i--) {
        while(!st.empty() && nums[st.top()]<nums[i]) {
            st.pop();
        }
        Nmax[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = 0; i<n; i++) {
        while(!st.empty() && nums[st.top()]>=nums[i]) {
            st.pop();
        }
        Pmin[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n-1; i>=0; i--) {
        while(!st.empty() && nums[st.top()]>nums[i]) {
            st.pop();
        }
        Nmin[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    long long answer = 0;
    for (int i = 0; i<n; i++) {
        long long Lmax = i-Pmax[i];
        long long Rmax = Nmax[i]-i;
        ll cntMax = countPairs(Lmax, Rmax, k);
        answer += nums[i] * cntMax;
        ll Lmin = i - Pmin[i];
        ll Rmin = Nmin[i] - i;
        ll cntMin = countPairs(Lmin, Rmin, k);
        answer += nums[i] * cntMin;
    }
    cout << answer << "\n";
    return answer;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    minMaxSubarraySum(nums, k);
}