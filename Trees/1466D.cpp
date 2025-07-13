#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> vertex(n+1);
        vector<long long> degree(n+1);
        for (long long i = 1; i<=n; i++) {
            cin >> vertex[i];
        }
        for (long long i = 0; i<n-1; i++) {
            long long temp1, temp2;
            cin >> temp1 >> temp2;
            degree[temp1]++;
            degree[temp2]++;
        }
        priority_queue<long long> pq;
        for (long long i = 1; i<=n; i++) {
            for (long long j = 0; j<degree[i]-1; j++) {
                pq.push(vertex[i]);
            }
        }
        long long sum = accumulate(vertex.begin(), vertex.end(), 0LL);
        cout << sum << " ";
        for (long long i = 2; i<n; i++) {
            sum+=pq.top();
            pq.pop();
            cout << sum << " ";
        }
        cout << "\n";
    }
}