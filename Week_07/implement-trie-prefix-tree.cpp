class Trie {
    struct TrieNode {
        map<char, TrieNode*> children;
        int end;
        TrieNode() : end(0) {};
    };
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->end = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, true);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, false);
    }

private:
    bool find(string word, bool exact) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children.count(c) == 0) {
                return false;
            }
            cur = cur->children[c];
        }
        return exact ? cur->end : true;
    }

    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */