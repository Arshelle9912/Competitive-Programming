#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)9e18;
vector<vector<int>> people;
vector<long long> dp;
int n, m;
long long b;
long long answer = INF;
void f(int index) {
    if (people.size()==index) {
        return;
    }
    long long k = people[index][0];
    long long cost = people[index][1];
    int cover = people[index][2];
    int FULL = (1<<m) - 1;
    for(int mask = FULL; mask >= 0; --mask){
        long long cand = dp[mask] + cost;
        int nm = mask | cover;
        if (cand < dp[nm]) dp[nm] = cand;
    }
    if (dp[FULL] < INF) {
        answer = min(answer, dp[FULL] + k * b);
    }
    f(index + 1);
}
int main() {
    cin >> n >> m >> b;
    people.assign(n, vector<int> (3));
    for (int i = 0; i<n; i++) {
        int cost, k, probs;
        cin >> cost >> k >> probs;
        int mask(0);
        for (int i = 0; i<probs; i++) {
            int num;
            cin >> num;
            mask |= (1<<(num-1));
        }
        people[i] = {k, cost, mask};
    }
    sort (people.begin(), people.end());
    dp.assign(1<<m, INF);
    dp[0] = 0;
    answer = INF;
    f(0);
    cout << (answer < INF ? answer : -1) << "\n";
}