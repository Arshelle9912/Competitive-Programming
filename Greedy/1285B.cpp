#include <bits/stdc++.h>
using namespace std;

long long kadane(vector<int> arr, int start, int end) {
    long long sum(0);
    long long best = INT_MIN;
    for (int i = start; i<end; i++) {
        if (sum<0) {
            sum=0;
        }
        sum+=arr[i];
        best = max(sum, best);
    }
    return best;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        long long yasser(0);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            yasser+=arr[i];
        }
        long long sum1 = kadane(arr, 0, n-1);
        long long sum2 = kadane(arr, 1, n);
        long long adel = max(sum1, sum2);
        if (yasser>adel) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}