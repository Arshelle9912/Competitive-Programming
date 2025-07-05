#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> left(INT_MAX, -1);
        pair<int, int> secondLeft(INT_MAX, -1);
        pair<int, int> right(0, -1);
        pair<int, int> secondRight(0, -1);
        pair<int, int> upper(INT_MAX, -1);
        pair<int, int> secondUpper(INT_MAX, -1);
        pair<int, int> lower(0, -1);
        pair<int, int> secondLower(0, -1);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i].first >> arr[i].second;
            if (arr[i].first<secondLeft.first) {
                secondLeft.first = arr[i].first;
                secondLeft.second = i;
                if (arr[i].first<left.first) {
                    secondLeft = left;
                    left.first = arr[i].first;
                    left.second = i;
                }
            }
            if (arr[i].first>secondRight.first) {
                secondRight.first = arr[i].first;
                secondRight.second = i;
                if (arr[i].first>right.first) {
                    secondRight = right;
                    right.first = arr[i].first;
                    right.second = i;
                }
            }
            if (arr[i].second<secondUpper.first) {
                secondUpper.first = arr[i].second;
                secondUpper.second = i;
                if (arr[i].second<upper.first) {
                    secondUpper = upper;
                    upper.first = arr[i].second;
                    upper.second = i;
                }
            }
            if (arr[i].second>secondLower.first) {
                secondLower.first = arr[i].second;
                secondLower.second = i;
                if (arr[i].second>lower.first) {
                    secondLower = lower;
                    lower.first = arr[i].second;
                    lower.second = i;
                }
            }
        }
        if (n==1) {
            cout << 1 << "\n";
            continue;
        }
        long long ans = 1LL*(right.first-left.first+1)*(lower.first-upper.first+1);
        if (left.first != secondLeft.first) {
            if (left.second == upper.second) {
                if (1LL*(right.first-secondLeft.first+1)*(lower.first-secondUpper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(right.first-secondLeft.first+1)*(lower.first-secondUpper.first+1));
                } else {
                    long long area = min(1LL*(right.first-secondLeft.first+2)*(lower.first-secondUpper.first+1), 1LL*(right.first-secondLeft.first+1)*(lower.first-secondUpper.first+2));
                    ans = min(ans, area);
                }
            } else if (left.second == lower.second) {
                if (1LL*(right.first-secondLeft.first+1)*(secondLower.first-upper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(right.first-secondLeft.first+1)*(secondLower.first-upper.first+1));
                } else {
                    long long area = min(1LL*(right.first-secondLeft.first+2)*(secondLower.first-upper.first+1), 1LL*(right.first-secondLeft.first+1)*(secondLower.first-upper.first+2));
                    ans = min(ans, area);
                }
            } else {
                if (1LL*(right.first-secondLeft.first+1)*(lower.first-upper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(right.first-secondLeft.first+1)*(lower.first-upper.first+1));
                } else {
                    long long area = min(1LL*(right.first-secondLeft.first+2)*(lower.first-upper.first+1), 1LL*(right.first-secondLeft.first+1)*(lower.first-upper.first+2));
                    ans = min(ans, area);
                }
            }
        }
        if (right.first != secondRight.first) {
            if (right.second == upper.second) {
                if (1LL*(secondRight.first-left.first+1)*(lower.first-secondUpper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(secondRight.first-left.first+1)*(lower.first-secondUpper.first+1));
                } else {
                    long long area = min(1LL*(secondRight.first-left.first+2)*(lower.first-secondUpper.first+1), 1LL*(secondRight.first-left.first+1)*(lower.first-secondUpper.first+2));
                    ans = min(ans, area);
                }
            } else if (right.second == lower.second) {
                if (1LL*(secondRight.first-left.first+1)*(secondLower.first-upper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(secondRight.first-left.first+1)*(secondLower.first-upper.first+1));
                } else {
                    long long area = min(1LL*(secondRight.first-left.first+2)*(secondLower.first-upper.first+1), 1LL*(secondRight.first-left.first+1)*(secondLower.first-upper.first+2));
                    ans = min(ans, area);
                }
            } else {
                if (1LL*(secondRight.first-left.first+1)*(lower.first-upper.first+1)!=n-1) {
                    ans = min(ans, 1LL*(secondRight.first-left.first+1)*(lower.first-upper.first+1));
                } else {
                    long long area = min(1LL*(secondRight.first-left.first+2)*(lower.first-upper.first+1), 1LL*(secondRight.first-left.first+1)*(lower.first-upper.first+2));
                    ans = min(ans, area);
                }
            }
        }
        if (upper.first != secondUpper.first) {
            if (1LL*(right.first-left.first+1)*(lower.first-secondUpper.first+1)!=n-1) {
                ans = min(ans, 1LL*(right.first-left.first+1)*(lower.first-secondUpper.first+1));
            } else {
                long long area = min(1LL*(right.first-left.first+2)*(lower.first-secondUpper.first+1), 1LL*(right.first-left.first+1)*(lower.first-secondUpper.first+2));
                ans = min(ans, area);
            }
        }
        if (lower.first != secondLower.first) {
            if (1LL*(right.first-left.first+1)*(secondLower.first-upper.first+1)!=n-1) {
                ans = min(ans, 1LL*(right.first-left.first+1)*(secondLower.first-upper.first+1));
            } else {
                long long area = min(1LL*(right.first-left.first+2)*(secondLower.first-upper.first+1), 1LL*(right.first-left.first+1)*(secondLower.first-upper.first+2));
                ans = min(ans, area);
            }
        }
        cout << ans << "\n";
    }
}