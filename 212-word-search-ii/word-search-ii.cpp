class Solution {
public:
    vector<string> result;
    int m, n;
    
    struct trieNode {
        bool endOfWord;
        char ch;
        trieNode* children[26];
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        for(int i = 0; i<26; i++) {
            newNode->children[i] = NULL;
        }
        
        newNode->ch = ' ';
        return newNode;
    }
    
    void insert(trieNode* root, string &word) {
        trieNode* pCrawl = root;
        
        for(int i = 0; i<word.length(); i++) {
            char ch = word[i];
            int idx = ch-'a';
            
            if(pCrawl->children[idx] == NULL) {
                pCrawl->children[idx] = getNode();
                pCrawl->children[idx]->ch = ch;
            }
            
            pCrawl = pCrawl->children[idx];
        }
        
        pCrawl->endOfWord = true;
    }
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root, string s) {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        
        char ch = board[i][j];
        int idx = ch-'a';
        if(board[i][j] == '$' || root->children[idx] == NULL)
            return;
        
        root = root->children[idx];
        s.push_back(ch);
        if(root->endOfWord == true) {
            result.push_back(s);
            root->endOfWord = false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            findWords(board, new_i, new_j, root, s);
        }
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        trieNode* root = getNode();
        
        for(string &word : words) {
            insert(root, word);
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                char ch = board[i][j];
                int idx = ch-'a';
                string s = "";
                if(root->children[idx] != NULL)
                    findWords(board, i, j, root,s);
            }
        }
        
        return result;
    }
};