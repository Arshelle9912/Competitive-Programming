#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            for (int i = 0; i<26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    TrieNode* findNode(const string& s) const {
        TrieNode* node = root;
        for (char c : s) {
            if (!node->children[c-'a']) {
                return nullptr;
            }
            node = node->children[c-'a'];
        }
        return node;
    }

    void dfs(TrieNode* node, string& max, string& curr) {
        for (int i = 0; i<26; i++) {
            TrieNode* child = node->children[i];
            if (!child || !child->isEnd) {
                continue;
            }
            curr.push_back('a'+i);
            if (curr.length()>max.length()) {
                max = curr;
            }
            dfs(node->children[i], max, curr);
            curr.pop_back();
        }
    }

    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(const string& word) const {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c-'a']) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->isEnd = true;
        }
        bool search(string& word) {
            TrieNode* node = findNode(word);
            return node && node->isEnd;
        }
        bool startsWith(string& word) {
            return findNode(word);
        }

        string ans() {
            TrieNode* node = root;
            string max = "";
            string curr = "";
            dfs(node, max, curr);
            return max;
        }
};

string longestWord(vector<string>& words) {
    Trie trie;
    for (string s : words) {
        trie.insert(s);
    }
    return trie.ans();
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i<n; i++) {
        cin >> words[i];
    }
    cout << longestWord(words);
}