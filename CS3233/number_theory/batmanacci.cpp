#include <bits/stdc++.h>
using namespace std;
char recurse(int n, long long k, vector<long long>& len) {    
    if (n==1 || n==2) {
        if (n==1) return 'N';
        else return 'A';
    }
    if (k<=len[n-2]) {
        return recurse(n-2, k, len);
    } else {
        return recurse(n-1, k-len[n-2], len);
    }
}
int main() {
    string last = "A";
    string secondLast = "N";
    long long n, k;
    cin >> n >> k;
    vector<long long> len(max(3LL, n+1));
    len[1] = 1;
    len[2] = 1;
    long long upper = 4e18;
    for (int i = 3; i<=n; i++) {
        len[i] = min(upper, len[i-1] + len[i-2]);
    }
    printf("%c\n", recurse(n, k, len));
}