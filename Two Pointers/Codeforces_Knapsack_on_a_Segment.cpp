#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> weights(n);
    vector<int> costs(n);
    for (int i = 0; i<n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> costs[i];
    }
    int low(0), weight(0);
    long long max_cost(0), cost(0);
    for (int i = 0; i<n; i++) {
        weight += weights[i];
        cost += costs[i];
        while (weight > s) {
            weight -= weights[low];
            cost -= costs[low];
            low++;
        }
        max_cost = max(cost, max_cost);
    }
    cout << max_cost << endl;
}