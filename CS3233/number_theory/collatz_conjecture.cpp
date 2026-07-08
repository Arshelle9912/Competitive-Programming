#include <bits/stdc++.h>
using namespace std;
long long gcd (long long a, long long b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    unordered_set<long long> se;
    for (long long i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long long> curr, temp;
    for (long long i = 0; i<n; i++) {
        unordered_set<long long> se1;
        temp.clear();
        temp.push_back(arr[i]);
        se1.insert(arr[i]);
        se.insert(arr[i]);
        for (long long x : curr) {
            long long g = gcd(x, arr[i]);
            if (se1.find(g) == se1.end()) {
                temp.push_back(g);
                se1.insert(g);
                se.insert(g);
            }
        }
        curr = temp; 
    }
    printf("%d\n", se.size());
}