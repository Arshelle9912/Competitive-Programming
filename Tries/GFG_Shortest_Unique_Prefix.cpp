#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isEnd;
        int count;
        TrieNode(): isEnd(false) {
            count = 0;
        }
    };
    TrieNode* root;
    TrieNode* findNode(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            auto it = node->children.find(c);
            if (it == node->children.end())
                return nullptr;
            node = it->second;
        }
        return node;
    }

    string findPrefix(string& word) {
        string pref = "";
        string curr = "";
        TrieNode* node = root;
        for (int i = 0; i<word.length(); i++) {
            char c = word[i];
            curr+=c;
            if (node->children.size() > 1) {
                pref = curr;
            }
            node = node->children[c];
        }
        return pref;
    }

    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->count++;
            }
            node->isEnd = true;
        }
        bool search(string& word) {
            TrieNode* node = findNode(word);
            return node && node->isEnd;
        }
        bool startsWith(string& prefix) {
            return findNode(prefix)!=nullptr;
        }
        string pref(string& word) {
            return findPrefix(word);
        }
};
vector<string> findPrefixes(string arr[], int n) {
    vector<string> ans(n);
    Trie trie;
    for (int i = 0; i<n; i++) {
        trie.insert(arr[i]);
    }
    for (int i = 0; i<n; i++) {
        ans[i] = trie.pref(arr[i]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    string* arr = new string[n];
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<string> ans = findPrefixes(arr, n);
    for (string s : ans) {
        cout << s << "\n";
    }
}