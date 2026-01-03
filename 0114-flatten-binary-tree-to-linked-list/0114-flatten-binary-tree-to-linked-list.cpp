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
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->left);

        TreeNode* temp = root->right;
        TreeNode* t1 = root;
        root->right = root->left;
        root->left = NULL;
        while(t1->right != NULL) {
            t1 = t1->right;
        }
        t1->right = temp;

        flatten(temp);
    }
};