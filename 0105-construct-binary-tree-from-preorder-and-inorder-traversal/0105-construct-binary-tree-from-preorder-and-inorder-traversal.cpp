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
    
    TreeNode* createTree(vector<int>& preorder, unordered_map<int, int> &mp, int &i, int s, int e) {
        if(s > e || i >= preorder.size()) return NULL;

        int rootVal = preorder[i++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];
        root->left = createTree(preorder, mp, i, s, mid-1);
        root->right = createTree(preorder, mp, i, mid+1, e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int preorderIdx = 0;
        return createTree(preorder, mp, preorderIdx, 0, inorder.size()-1);
    }
};