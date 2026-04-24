#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;

    int n;
    cin >> n;

    while (n--) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    string searchWord;
    cin >> searchWord;

    cout << "Search: " << (trie.search(searchWord) ? "Found" : "Not Found") << endl;

    string prefix;
    cin >> prefix;

    cout << "StartsWith: " << (trie.startsWith(prefix) ? "Yes" : "No") << endl;

    return 0;
}
