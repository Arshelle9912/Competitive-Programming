#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
int main() {
    pbds tree;
    tree.insert(1);
    tree.insert(10);

    for (auto i : tree) cout << i << " ";
    cout << "\n";

    // finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << tree.order_of_key(6) << endl; 

    // finding kth element - 4th query
    cout << "0th element " << *tree.find_by_order(0) << "\n";

    // lower bound -> Lower Bound of X = first element >= X in the set
    cout << "Lower Bound of 8: " << *tree.lower_bound(8) << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 8: " << *tree.upper_bound(8) << endl;
}