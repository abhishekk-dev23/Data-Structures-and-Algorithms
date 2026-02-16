class TrieNode{
public:
    
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(){
        for(auto& c: children) c = nullptr;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    };
    
    void insert(string word) {
       TrieNode* temp = root;
       for(auto& c: word) {
            int i = c - 'a';
            if(!temp->children[i]) temp->children[i] = new TrieNode();
            temp = temp->children[i];
       }
       temp->isTerminal = true;
       return;
    }
    
    bool search(string word, bool isPrefix = false) {
        TrieNode* temp = root;
        for(auto& c: word) {
            int i = c - 'a';
            if(!temp->children[i]) return false;

            temp = temp->children[i];
        }

        if(!isPrefix) return temp -> isTerminal;
        return true;
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

