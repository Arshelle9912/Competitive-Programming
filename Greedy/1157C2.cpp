#include <bits/stdc++.h>
using namespace std;

string count(vector<int> arr, int left, int right) {
    int result1(0);
    int result2(0);
    int last = arr[left];
    for (int i = left+1; i<arr.size(); i++) {
        if (arr[i]>last) {
            result1++;
            last = arr[i];
        } else {
            break;
        }
    }
    last = arr[right];
    for (int i = right-1; i>=0; i--) {
        if (arr[i]>last) {
            result2++;
            last=arr[i];
        } else {
            break;
        }
    }
    return result1>result2 ? "L" : "R";
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int left(0), right(n-1);
    int last(0);
    string ans = "";
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++) {
        if (arr[left]<arr[right]) {
            if (arr[left]>last) {
                last = arr[left];
                left++;
                ans += "L";
            } else if (arr[right]>last){
                last = arr[right];
                right--;
                ans += "R";
            } else {
                cout << ans.length() << "\n";
                cout << ans << "\n";
                return 0;
            }
        } else if (arr[right]<arr[left]) {
            if (arr[right]>last) {
                last = arr[right];
                right--;
                ans += "R";
            } else if (arr[left]>last){
                last = arr[left];
                left++;
                ans += "L";
            } else {
                cout << ans.length() << "\n";
                cout << ans << "\n";
                return 0;
            }
        } else {
            if (arr[left]<=last) {
                cout << ans.length() << "\n";
                cout << ans << "\n";
                return 0;
            }
            string check = count(arr, left, right);
            if (check=="L") {
                last = arr[left];
                left++;
                ans += "L";
            } else {
                last = arr[right];
                right--;
                ans += "R";
            }
        }
    }
    cout << ans.length() << "\n";
    cout << ans << "\n";
}