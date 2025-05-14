#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> toCheck = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 36, 49};
    int cnt = 0;
    string response;

    for (auto x : toCheck) {
        cout << x << endl;

        cin >> response;
        if (response == "yes") {
            cnt++;
        }

        if (cnt > 1) {
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
    return 0;
}
