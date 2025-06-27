#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n+1);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long> spf(arr[n-1]+1);
    vector<long> sequenceLength(arr[n-1]+1);
    for (long p=2; p<=arr[n-1]; p++) {
        if (spf[p]==0) {
            for (long q=p; q<=arr[n-1]; q+=p) {
                spf[q] = p;
            }
        }
    }
    long long maximum(1);
    for (long p = 0; p<n; p++) {
        long long current = arr[p];
        long long count = 0;
        while (current>1) {
            if (count<=sequenceLength[spf[current]]) {
                count = 1+sequenceLength[spf[current]];
            }
            current/=spf[current];
        }
        if (count>maximum) {
            maximum = count;
        }
        current = arr[p];
        while (current>1) {
            if (sequenceLength[spf[current]]<count) {
                sequenceLength[spf[current]] = count;
            }
            current/=spf[current];
        }
    }
    cout << maximum << "\n";
}