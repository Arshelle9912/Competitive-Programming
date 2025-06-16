#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, T, easy, hard;
        cin >> n >> T >> easy >> hard;
        vector<long long> diff(n);
        vector<pair<long long, long long>> mand(n);
        long long easyNum = 0; long long hardNum = 0;
        for (long long i = 0; i<n; i++) {
            cin >> diff[i];
            diff[i]==0 ? easyNum++ : hardNum++;
        }
        for (long long i = 0; i<n; i++) {
            cin >> mand[i].first;
            mand[i].second = diff[i];
        }
        long long best(0);
        mand.emplace_back(T+1, 0);
        sort(mand.begin(), mand.end());
        long long timeSpent(0); long long mandSolved(0);
        for (pair<long long, long long> p : mand) {
            long long end = p.first;
            long long type = p.second;
            long long limit = end-1;
            long long left = limit-timeSpent;
            if (left>=0) {
                long long easyMax = min(easyNum, left/easy);
                left -= easyMax*easy;
                long long hardMax = min(hardNum, left/hard);
                best = max(best, easyMax+hardMax+mandSolved);
            }
            long long cost = (type==0) ? easy : hard;
            timeSpent+=cost;
            mandSolved++;
            (type==0) ? easyNum-- : hardNum--;
            if (timeSpent>T) {
                break;
            }
        }
        cout << best << "\n";
    }
}