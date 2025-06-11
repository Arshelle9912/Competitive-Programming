#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    TrieNode* root;

    TrieNode* findNode(const string& s) const {
        TrieNode* node = root;
        for (char c: s) {
            if (!node->children[c-'a']) {
                return nullptr;
            }
            node = node->children[c-'a'];
        }
        return node;
    }

    public: 
        Trie() {
            root = new TrieNode();
        }

        void insert(const string& word) {
            TrieNode* node = root;
            for (char c:word) {
                if (!node->children[c-'a']) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->isEnd=true;
        }
        bool search(const string& word) {
            TrieNode* node = findNode(word);
            return node && node->isEnd;
        }
        bool startsWith(const string& prefix) {
            return findNode(prefix)!=nullptr;
        }
};