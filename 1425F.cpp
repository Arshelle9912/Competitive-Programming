#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, fin;
    cin >> n;
    
    vector<int> flamingo(n);
    vector<int> response(n + 1);
    
    cout << "? 1 2" << endl;
    cout.flush();
    cin >> response[2];
    
    for (int i = 3; i <= n; ++i) {
        cout << "? 1 " << i << endl;
        cout.flush();
        cin >> response[i];
        flamingo[i - 1] = response[i] - response[i - 1];
    }
    
    cout << "? 2 3" << endl;
    cout.flush();
    cin >> fin;
    
    flamingo[0] = response[3] - fin;
    flamingo[1] = response[2] - flamingo[0];
    
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << flamingo[i] << " "; 
    }
    cout << endl;
    return 0;
}
