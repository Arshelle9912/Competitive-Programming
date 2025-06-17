#include <bits/stdc++.h>
using namespace std;

long long solve (long long a, long long b, long long result) {
    if (b==0) {
        return result;
    }
    result+=a/b;
    return solve(b, a%b, result);
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b, 0);
}