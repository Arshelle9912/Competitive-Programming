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

        void insert(int& num) {
            TrieNode* node = root;
            for (int k = 30; k>=0; k--) {
                int bit = (num>>k) & 1;
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
            node->isEnd = true;
        }

        int query(int num) {
            TrieNode* node = root;
            int ans = 0;
            for (int k = 30; k>=0; k--) {
                int bit = (num>>k) & 1;
                if (node->children[1-bit]) {
                    ans |= (1<<k);
                    node = node->children[1-bit];
                } else {
                    node = node->children[bit];
                }
            }
            return ans;
        }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (int num : nums) {
        trie.insert(num);
    }
    int maximum = INT_MIN;
    for (int num : nums) {
        maximum = max(trie.query(num), maximum);
    }
    return maximum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    cout << findMaximumXOR(nums);
}