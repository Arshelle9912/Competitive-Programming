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
    
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;
            for (int i = 21; i>=0; i--) {
                int bit = (num>>i)&1;
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
            node->isEnd = true;
        }
        int maxXOR(int num) {
            TrieNode* node = root;
            int ans = 0;
            for (int i = 21; i>=0; i--) {
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

int maxSubarrayXOR(int N, int arr[]) {
    Trie trie;
    int last = 0;
    trie.insert(0);
    int maximum = INT_MIN;
    for (int i = 0; i<N; i++) {
        last = last^arr[i];
        trie.insert(last);
        maximum = max(trie.maxXOR(last), maximum);
    }
    return maximum;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << maxSubarrayXOR(n, arr);
}