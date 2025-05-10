#include <bits/stdc++.h>
using namespace std;

bool checker(const vector<int>&, int, long long, long long, long long, long long, long long);
long long lcm(long long, long long);
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        int result = -1;
        vector<int> tickets(n);
        for (int j = 0; j<n; j++) {
            cin >> tickets[j];
        }
        int low = 0, high = n;
        long long x, a, y, b;
        cin >> x >> a;
        cin >> y >> b;
        long long target;
        cin >> target;
        sort(tickets.rbegin(), tickets.rend());
        while (low <= high) {
            int mid = (low + high)/2;
            if (checker(tickets, mid, x, a, y, b, target)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << result << endl;
    }
}

bool checker(const vector<int>& tickets, int mid, long long x, long long a, long long y, long long b, long long target) {
    long long sum(0);
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    long long numLCM = mid/lcm(a, b);
    long long numA = mid/a - numLCM;
    long long numB = mid/b - numLCM;
    for (int i = 0; i < numLCM; i++) {
        sum += (long long)(x+y) * tickets[i];
    }
    for (int j = numLCM; j<(numA+numLCM); j++) {
        sum += (long long)x * tickets[j];
    }
    for (int k = (numLCM + numA); k<(numB+numLCM+numA); k++) {
        sum += (long long)y * tickets[k];
    }
    return sum>=(target*100);
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
