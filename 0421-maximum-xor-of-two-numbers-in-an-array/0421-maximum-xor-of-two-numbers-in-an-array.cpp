class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        for(auto& c: children) c = nullptr;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie () {
        root = new TrieNode();
    }

public:
    void insert(int num) {
        TrieNode* temp = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!temp->children[bit]) {
                temp->children[bit] = new TrieNode();
            }
            temp = temp->children[bit];
        }
    }
public:
    int getMaxValue(int x) {
        TrieNode* temp = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            int bit = (x >> i) & 1;
            if(temp->children[(1 - bit)]) {
                maxNum = maxNum | (1<<i);
                temp = temp->children[(1-bit)];
            }
            else{
                temp = temp->children[bit];
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        Trie tr;
        int max_val = 0;

        for(int i=0; i<nums.size(); i++) {
            tr.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++) {
            int val = tr.getMaxValue(nums[i]);
            max_val = max(max_val, val);
        }
        return max_val;
    }
};