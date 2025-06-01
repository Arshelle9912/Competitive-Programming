#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j<t; j++) {
        string s, result;
        cin >> s;
        int deletions;
        cin >> deletions;
        deque<int> nums[10];
        for (int i = 0; i<s.size(); i++) {
            nums[s[i]-'0'].push_back(i);
        }
        for (int i = 0; i<s.size(); i++) {
            int current = s.size(), new_index = s.size();
            for (int k = 0; k<10; k++) {
                if (nums[k].size()) {
                    current = min(current, nums[k].front());
                }
            }
            for (int k = (i==0); k<10; k++) {
                if (nums[k].size() && nums[k].front()-current<=deletions) {
                    result += ('0'+k);
                    new_index = nums[k].front();
                    break;
                }
            }
            deletions-=new_index-current;
            for (int k = 0; k<10; k++) {
                while (nums[k].size() && nums[k].front()<=new_index) {
                    nums[k].pop_front();
                }
            }
        }
        cout << string(result.begin(), result.end() - deletions) << "\n";
    }
}