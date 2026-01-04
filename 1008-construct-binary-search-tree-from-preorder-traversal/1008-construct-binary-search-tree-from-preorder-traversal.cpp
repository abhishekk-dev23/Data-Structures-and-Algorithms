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
    TreeNode* addChild(TreeNode* &root, int d) {
        if(root == NULL) {
            root = new TreeNode(d);
            return root;
        };

        if(d < root->val) {
            root->left = addChild(root->left, d);
        }
        else{
            root->right = addChild(root->right, d);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for(int i=0; i<preorder.size(); i++) {
            root = addChild(root, preorder[i]);
        }
        return root;
    }
};













