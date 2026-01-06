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
    TreeNode* buildBST(vector<int> &pre, int &i, int mini, int maxi) {
        if(i >= pre.size()) return NULL;
        if(pre[i] < mini || pre[i] > maxi) return NULL;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = buildBST(pre, i, mini, root->val);
        root->right = buildBST(pre, i, root->val, maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() <= 0) return NULL;
        int i = 0;
        return buildBST(preorder, i, INT_MIN, INT_MAX);
    }
};