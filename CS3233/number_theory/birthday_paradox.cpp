#include <bits/stdc++.h>
using namespace std;
long long ncr(long long n, long long r) {
    r = min(r, n-r);
    long long ans = 1;
    for (int i = 1; i<=r; i++) {
        ans = (ans*(n-r+i))/i;
    }
    return ans;
}
long long factorial (int num) {
    long long ans = 1;
    for (int i = 2; i<=num; i++) {
        ans*=i;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int upper = 0;
    vector<int> arr(366);
    int sum = 0;
    for (int i = 0; i<n; i++) {
        int num;
        cin >> num;
        arr[num]++;
        sum+=num;
        upper = max(upper, num);
    }
    int tot = sum;
    vector<double> logfact(sum + 1, 0.0);
    for (int i = 1; i <= sum; i++) logfact[i] = logfact[i - 1] + log10((double)i);
    double ans = 0;
    int start = 365;
    for (int i = upper; i>0; i--) {
        if (arr[i]==0) continue;
        for (int j = 0; j<arr[i]; j++) {
            ans += log10(start);
            start--;
        }
        ans += logfact[sum];
        ans -= arr[i] * logfact[i];
        ans -= logfact[arr[i]];
        ans -= logfact[sum - arr[i] * i];
        sum -= arr[i] * i;
    }
    ans-=(tot*log10(365));
    cout << fixed << setprecision(15) << ans << "\n";
}