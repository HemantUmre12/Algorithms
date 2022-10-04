class Trie {
    
private:
    
    struct TrieNode {
        
        vector<TrieNode*> links;
        vector<int> list;
        bool isWord;
        
        TrieNode() {
            links.resize(26, NULL);
            isWord = false;
        }
        
        ~TrieNode() {
            for(auto &node : links) {
                delete node;
            }
        }
    };
    
    TrieNode* root;
    
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(string &word) {
        TrieNode* node = root;
        for(auto &ch : word) {
            int idx = ch - 'a';
            if(!node->links[idx]) {
                node->links[idx] = new TrieNode();
            }
            node = node->links[idx];
        }
        node->isLeaf = true;
    }
    
    vector<int> makesPalindrome(string word) {
        TrieNode* node = root;
        for(auto &ch : word) {
            int idx = ch - 'a';
            if(!node->links[idx]) {
                return false;
            }
            node = node->links[idx];
        }
        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &ch : prefix) {
            int idx = ch - 'a';
            if(!node->links[idx]) {
                return false;
            }
            node = node->links[idx];
        }
        return true;        
    }
};
