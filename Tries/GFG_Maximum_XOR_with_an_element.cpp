#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* children[2];
        bool isEnd;
        TrieNode() : isEnd(false) {
            for (int i = 0; i<2; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

    public :
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;
            for (int i = 30; i>=0; i--) {
                int bit = (num>>i)&1;
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
            node->isEnd = true;
        }

        int maximum(int num) {
            TrieNode* node = root;
            int ans = 0;
            for (int i = 30; i>=0; i--) {
                int bit = (num>>i)&1;
                if (node->children[1-bit]) {
                    ans |= (1<<i);
                    node = node->children[1-bit];
                } else {
                    node = node->children[bit];
                }
            }
            return ans;
        }
};

vector<int> maxXor(vector<int> &arr, vector<vector<int>> &queries) {
    sort(arr.begin(), arr.end());
    int n = queries.size();
    for (int i = 0; i<n; i++) {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), 
    [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    Trie trie;
    vector<int> result(n);
    int j(0);
    for (vector<int> a : queries) {
        int first = a[0]; int second = a[1]; int size = arr.size(); int third = a[2];
        while (j<size && arr[j]<=second) {
            trie.insert(arr[j]);
            j++;
        }
        if (j==0) {
            result[third]=-1;
        } else {
            result[third]=trie.maximum(first);
        }
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<m; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = maxXor(arr, queries);
    for (int a : ans) {
        cout << a << "\n";
    }
}