#include <bits/stdc++.h>
using namespace std;
bool checker(vector<long long>& times, long long t, long long pos) {
    long long n = times.size();
    long long produced = 0;
    for (long long i = 0; i<n; i++) {
        produced+=(t/times[i]);
        if (produced >= pos) return true;
    }
    return produced>=pos;
}
int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> times(n);
    long long low = 0; 
    long long high = 1e18;
    for (long long i = 0; i<n; i++) {
        cin >> times[i];
    }
    long long ans;
    while (low<=high) {
        long long mid = (low+high)/2;
        if (checker(times, mid, m+1)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    printf("%lld\n", ans);
}