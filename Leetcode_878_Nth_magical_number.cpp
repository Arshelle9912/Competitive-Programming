#include <iostream>
using namespace std;

int lcm(int a, int b) {
    int greater = max(a,b);
    int smaller = min(a,b);
    for (int i = greater; ;i+=greater) {
        if (i%smaller == 0) {
            return i;
        }
    }
}
int main() {
    long long n, a, b, ans;
    const int mod = 1e9 + 7;
    cin >> n >> a >> b;
    long long high = n * 1ll * min(a,b);
    long long low = min(a,b);
    while (low <= high) {
        long long mid = low + (high-low)/2;
        long long countA = mid/a;
        long long countB = mid/b;
        long long countC = mid/(lcm(a,b));
        long long count = countA + countB - countC;
        if (count < n) {
            low = mid+1;
        } else if (count > n) {
            high = mid - 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans;
    return ans % mod;
}