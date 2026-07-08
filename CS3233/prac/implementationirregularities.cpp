#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> time(n);
    vector<long long> finishTime(n);
    vector<pair<long long, long long>> comb(n);
    for (long long i = 0; i<n; i++) {
        cin >> time[i];
    }
    for (long long i = 0; i<n; i++) {
        cin >> finishTime[i];
    }
    for (long long i = 0; i<n; i++) {
        comb[i] = {finishTime[i], time[i]};
    }
    pair<long long, long long> machine = {0, 0};
    long long numMachines = 1;
    sort(comb.begin(), comb.end());
    for (long long i = 0; i<n; i++) {
        if (comb[i].first==-1) continue;
        long long sec = machine.second;
        machine.second = comb[i].first;
        machine.first += (machine.second-sec) * numMachines;
        // cout << machine.first << "\n";
        if (comb[i].second>machine.first) {
            long long machinesNeeded = (comb[i].second-machine.first + machine.second - 1)/machine.second;
            numMachines+=machinesNeeded;
            machine.first = machine.first+machine.second*machinesNeeded - comb[i].second;
        } else {
            machine.first-=comb[i].second;
        }
    }
    cout << numMachines << "\n";
}