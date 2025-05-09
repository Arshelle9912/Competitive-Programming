#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int> > productPair = {
        {32,  {4, 8}},
        {60,  {4, 15}},
        {64,  {4, 16}},
        {92,  {4, 23}},
        {168, {4, 42}},
        {120, {8, 15}},
        {128, {8, 16}},
        {184, {8, 23}},
        {336, {8, 42}},
        {240, {15, 16}},
        {345, {15, 23}},
        {630, {15, 42}},
        {368, {16, 23}},
        {672, {16, 42}},
        {966, {23, 42}}
    };
    
    vector<int> result(6);
    int prod1, prod2, prod3, prod4;
    vector<int> pair1, pair2, pair3, pair4;
    cout << "? " << 1 << " " << 2 << endl;
    cin >> prod1;
    pair1 = productPair[prod1];
    cout << "? " << 2 << " " << 3 << endl;
    cin >> prod2;
    pair2 = productPair[prod2];
    if (pair1[0] == pair2[0] || pair1[0] == pair2[1]) {
        result[0] = pair1[1];
        result[1] = pair1[0];
    } else {
        result[0] = pair1[0];
        result[1] = pair1[1];
    }
    result[2] = (pair2[0] == result[1]) ? pair2[1] : pair2[0];
    cout << "? " << 4 << " " << 5 << endl;
    cin >> prod3;
    pair3 = productPair[prod3];
    cout << "? " << 5 << " " << 6 << endl;
    cin >> prod4;
    pair4 = productPair[prod4];
    if (pair3[0] == pair4[0] || pair3[0] == pair4[1]) {
        result[3] = pair3[1];
        result[4] = pair3[0];
    } else {
        result[3] = pair3[0];
        result[4] = pair3[1];
    }
    result[5] = (pair4[0] == result[4]) ? pair4[1] : pair4[0];
    cout << "! ";
    for (int i = 0; i<6; i++) {
        cout << result[i] << " ";
    }
}