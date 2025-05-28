#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<vector<int> > ms;
    vector<vector<int> > arr(n);
    vector<int> result(n);
    int rooms_used(0);
    for (int i = 0; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[i] = {temp1, temp2, i};
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i<n; i++) {
        if (!ms.empty() && ((*ms.begin())[0])<(arr[i][0])) {
            vector<int> temp = {arr[i][1], arr[i][0], (*ms.begin())[2], arr[i][2]};
            result[arr[i][2]] = (*ms.begin())[2];
            ms.erase(ms.begin());
            ms.insert(temp);
        } else {
            rooms_used++;
            vector<int> temp = {arr[i][1], arr[i][0], rooms_used, arr[i][2]};
            ms.insert(temp);
            result[arr[i][2]] = rooms_used;
        }
    }
    cout << rooms_used << "\n";
    for (int i = 0; i<n; i++) {
        cout << result[i] << " ";
    }
}