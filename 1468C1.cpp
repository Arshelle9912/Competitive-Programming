#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, index1, index2;
    cin >> n;
    int low = 1, high = n;
    cout << "? " << low << " " << high << endl;
    cin >> index1;
    bool leftSide;
    if (index1 == 1) {
        leftSide = false;
    } else {
        cout << "? " << 1 << " " << index1 << endl;
        cin >> index2;
        leftSide = (index1 == index2);
    }
    if (leftSide) {
        low = 1, high = index1 - 1;
        while (low < high) {
            int mid = (low + high + 1)/2;
            cout << "? " << mid << " " << index1 << endl;
            cin >> index2;
            if (index1 == index2) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
    }
    else{
        low = index1 + 1, high = n;
        while (low < high){
            int mid = (low+high)/2; 
            cout << "? " << index1 << " " << mid << endl;
            cin >> index2;
            if (index1 == index2) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    }
    cout << "! " << low << endl;
}