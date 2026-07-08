#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<double, double>> judges(n);
    vector<pair<double, double>> tar(m);
    vector<pair<double, double>> feather(p);
    priority_queue<tuple<long double, int, int>, vector<tuple<long double, int, int>>, greater<tuple<long double, int, int>>> pq;
    unordered_set<int> usedJudges1;
    unordered_set<int> usedJudges2;
    unordered_set<int> usedTar;
    unordered_set<int> usedFeather;
    for (int i = 0; i<n; i++) {
        cin >> judges[i].first >> judges[i].second;
    }
    for (int i = 0; i<m; i++) {
        cin >> tar[i].first >> tar[i].second;
    }
    for (int i = 0; i<p; i++) {
        cin >> feather[i].first >> feather[i].second;
    }
    long double total = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            long double dist = (tar[j].first-judges[i].first)*(tar[j].first-judges[i].first) 
            + (tar[j].second-judges[i].second)*(tar[j].second-judges[i].second);
            pq.push({dist, i, j});
        }
    }
    while (!pq.empty()) {
        auto [dist, i, j] = pq.top();
        pq.pop();
        if (usedJudges2.find(i)==usedJudges2.end() && usedTar.find(j)==usedTar.end()) {
            usedJudges2.insert(i);
            usedTar.insert(j);
            total += sqrt(dist);
        }
    }
    pq = decltype(pq)();
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<p; j++) {
            long double dist = (feather[j].first-judges[i].first)*(feather[j].first-judges[i].first) 
            + (feather[j].second-judges[i].second)*(feather[j].second-judges[i].second);
            pq.push({dist, i, j});
        }
    }
    while (!pq.empty()) {
        auto [dist, i, j] = pq.top();
        pq.pop();
        if (usedJudges1.find(i)==usedJudges1.end() && usedFeather.find(j)==usedFeather.end()) {
            usedJudges1.insert(i);
            usedFeather.insert(j);
            total += sqrt(dist);
        }
    }
    printf("%.7Lf\n", total);
}