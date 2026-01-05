/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createTree(vector<int> &preorder, int &i, unordered_map<int, int> &mp, int s, int e) {
        if(s > e || i >= preorder.size()) return NULL;
        int rootVal = preorder[i++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = createTree(preorder, i, mp, s, mid-1);
        root->right = createTree(preorder, i, mp, mid+1, e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() <= 0) return NULL;
        vector<int> pre = preorder;
        sort(preorder.begin(), preorder.end());
        unordered_map<int, int> mp;
        for(int i=0; i<preorder.size(); i++) {
            mp[preorder[i]] = i;
        }
        int preOrdIdx = 0;
        TreeNode* ans = createTree(pre, preOrdIdx, mp, 0, preorder.size()-1);
        return ans;
    }
    
};