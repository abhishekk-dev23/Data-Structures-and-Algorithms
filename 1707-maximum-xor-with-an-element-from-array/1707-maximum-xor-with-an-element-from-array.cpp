class Node {
public:
    Node* child[2];
    Node() {
        for(auto& c: child) c = nullptr;
    }
};
class Trie {
public:
    Node* root;
    Trie () {
        root = new Node();
    }

    void insert(int n) {
        Node* temp = root;
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(!temp->child[bit]) {
                temp->child[bit] = new Node();
            }
            temp = temp->child[bit];
        }
    }
    int getMaxVal(int n) {
        Node* temp = root;
        int maxVal = 0;
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(temp->child[(1 - bit)]) {
                maxVal = maxVal | (1 << i);
                temp = temp->child[(1 - bit)];
            }
            else{
                temp = temp->child[bit];
            }
        }
        return maxVal;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        int n = queries.size();
        for(int i=0; i<n; i++) {
                        // {mi, {xi , i}} -> storing because we want to sort
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());

        vector<int> ans(n, -1);
        int idx = 0;
        Trie tr;
        for(int i=0; i<n; i++) {
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qIdx = oQ[i].second.second;

            while(idx < nums.size() && nums[idx] <= mi) {
                tr.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[qIdx] = -1;
            else ans[qIdx] = tr.getMaxVal(xi);
        }
        
        return ans;
    }
};