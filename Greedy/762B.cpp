#include <bits/stdc++.h>
using namespace std;

int main() {
    long long usbnum, ps2num, bothnum, count(0), i(0), j(0), cost(0);
    vector<int> usb, ps2;
    cin >> usbnum >> ps2num >> bothnum;
    int cases;
    cin >> cases;
    for (int k = 0; k<cases; k++) {
        int temp;
        string s;
        cin >> temp >> s;
        if (s=="USB") {
            usb.push_back(temp);
        } else {
            ps2.push_back(temp);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    while (i<usb.size() && usbnum) {
        cost += usb[i];
        usbnum--;
        i++;
        count++;
    }
    while (j<ps2.size() && ps2num) {
        cost += ps2[j];
        ps2num--;
        j++;
        count++;
    }
    while ((j<ps2.size() || i<usb.size()) && bothnum) {
        if (j<ps2.size() && i<usb.size()) {
            if (ps2[j]<usb[i]) {
                cost+=ps2[j];
                j++;
            } else {
                cost+=usb[i];
                i++;
            }
        } else if (j>=ps2.size()) {
            cost+=usb[i];
            i++;
        } else {
            cost+=ps2[j];
            j++;
        }
        count++;
        bothnum--;
    }
    cout << count << " " << cost << "\n";
}