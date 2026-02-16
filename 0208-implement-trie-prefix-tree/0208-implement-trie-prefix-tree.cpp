class TrieNode{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode('\0');
    };
    
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        
        TrieNode *child;

        if (root->children[word[0] - 'a'] != NULL)
        { 
            child = root->children[word[0] - 'a'];
        }
        else
        { 
            child = new TrieNode(word[0]);
            root->children[word[0] - 'a'] = child;
        }

        
        insertUtil(child, word.substr(1));
    }
    void insert(string word){
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        
        TrieNode *child;

        if (root->children[word[0] - 'a'] != NULL)
        {
            child = root->children[word[0] - 'a'];
        }
        else 
        {
            return false;
        }
        
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
    bool checkPrefix(TrieNode* root, string word) {
        if(word.length() == 0) {
            return true;
        }
        TrieNode* child;

        if(root->children[word[0] - 'a'] != NULL) {
            child = root->children[word[0] - 'a'];
        }
        else{
            return false;
        }

        return checkPrefix(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return checkPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */