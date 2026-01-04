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
    void InOrder(TreeNode* root, vector<TreeNode*> &ans) {
        if(root == NULL) return;

        InOrder(root->left, ans);
        ans.push_back(root);
        InOrder(root->right, ans);
    }
    TreeNode* createBST(vector<TreeNode*> &ans, int s, int e) {
        int mid = s + (e-s)/2;
        if(s > e) return NULL;

        TreeNode* root = ans[mid];
        root->left = createBST(ans, s, mid-1);
        root->right = createBST(ans, mid+1, e);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return NULL;
        vector<TreeNode*> ans;
        InOrder(root, ans);
        
        return createBST(ans, 0, ans.size()-1);
    }
};




















