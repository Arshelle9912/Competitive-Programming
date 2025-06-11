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
            return node&&node->isEnd;
        }
        TrieNode* startsWith(string& word) {
            return findNode(word);
        }

        vector<string> getWordswithPrefix(const string& prefix) const {
            vector<string> result;
            TrieNode* node = findNode(prefix);
            if (!node) {
                return result;
            }
            string curr = prefix;
            dfs(node, curr, result);
            return result;
        }
};

vector<vector<string>> displayContacts(int n, string contact[], string s) {
    Trie trie;
    for (int i = 0; i<n; i++) {
        trie.insert(contact[i]);
    }

    vector<vector<string>> ans;
    for (int len = 1; len<=(int)s.size(); len++) {
        string pref = s.substr(0, len);
        auto bucket = trie.getWordswithPrefix(pref);
        if (bucket.empty())
            bucket.push_back("0");
        ans.push_back(bucket);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    string* contact = new string[n];
    for (int i = 0; i<n; i++) {
        cin >> contact[i];
    }
    string s;
    cin >> s;
    vector<vector<string>> result = displayContacts(n, contact, s);
    for (vector<string> v1 : result) {
        for (string v2 : v1) {
            cout << v2 << " ";
        }
        cout << "\n";
    }
}