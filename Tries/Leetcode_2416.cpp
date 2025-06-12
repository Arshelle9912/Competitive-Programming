#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* children[26];
        int cnt;
        TrieNode() : cnt(0) {
            memset(children, 0, sizeof(children));
        }
    };
    TrieNode* root;
    TrieNode* findNode(const string& s) const {
        TrieNode* node = root;
        for (char c : s) {
            if (!node->children[c-'a']) {
                return nullptr;
            }
            node=node->children[c-'a'];
        }
        return node;
    }

    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(const string& word) const {
            TrieNode* node = root;
            node->cnt++;
            for (char c : word) {
                if (!node->children[c-'a']) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
                node->cnt++;
            }
        }

        int score(const string& prefix) const {
            TrieNode* node = root;
            int total = 0;
            for (char c : prefix) {
                node = node->children[c-'a'];
                total+=node->cnt;
            }
            return total;
        }
};

vector<int> sumPrefixScores(vector<string>& words) {
    Trie trie;
    for (string s : words) {
        trie.insert(s);
    }
    vector<int> result;
    for (string s : words) {
        result.push_back(trie.score(s));
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i<n; i++) {
        cin >> words[i];
    }
    vector<int> result;
    result = sumPrefixScores(words);
    for (int v1 : result) {
        cout << v1 << "\n";
    }
}