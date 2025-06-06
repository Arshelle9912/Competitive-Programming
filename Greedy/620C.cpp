#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    long long segments(0);
    vector<pair<int, int>> result;
    set<int> s;
    int start=1;
    for (int i = 0; i<n; i++) {
        if (s.find(arr[i])!=s.end()) {
            segments++;
            result.push_back({start, i+1});
            start = i+2;
            s.clear();
        } else {
            s.insert(arr[i]);
        }
    }
    if (start!=n+1 && !result.empty()) {
        pair<int, int> last = result[result.size()-1];
        int temp = last.first;
        result.pop_back();
        result.push_back({temp, n});
    }
    if (segments == 0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << segments << "\n";
    for (int i = 0; i<segments; i++) {
        cout << result[i].first << " " << result[i].second << "\n";
    }
}