class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endofWord = false;
};

class WordDictionary {
    TrieNode* root;
public:        
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endofWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->endofWord;
        }

        char c = word[index];
        if (c == '.') {
            for (auto& [key, child] : node->children) {
                if (searchHelper(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[c]);
        }
    }
};
