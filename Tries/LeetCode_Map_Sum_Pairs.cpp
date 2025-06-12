#include <bits/stdc++.h>
using namespace std;

class MapSum {
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
    unordered_map<string,int> mp;
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

    void dfs(TrieNode* node, string& curr, vector<string>& out) const {
        if (node->isEnd) {
            out.push_back(curr);
        }
        for (int i = 0; i<26; i++) {
            if (!node->children[i]) {
                continue;
            }
            curr.push_back('a'+i);
            dfs(node->children[i], curr, out);
            curr.pop_back();
        }
    }
    public:
        MapSum() {
            root = new TrieNode();
        }
        void insert(const string& word, int val) {
            TrieNode* node = root;
            mp[word] = val;
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
            return node&&node->isEnd;
        }
        TrieNode* startsWith(string& word) {
            return findNode(word);
        }

        int sum(const string& prefix) const {
            vector<string> result;
            TrieNode* node = findNode(prefix);
            if (!node) {
                return 0;
            }
            string curr = prefix;
            dfs(node, curr, result);
            int total = 0;
            for (auto &k : result) {
                auto it = mp.find(k);
                if (it != mp.end())
                    total += it->second;
            }
            return total;
        }
};