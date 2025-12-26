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
    void inorder(TreeNode* root, int &min_diff, int &prev){
        if(root == NULL) return;

        inorder(root->left, min_diff, prev);
        if(prev != -1) {
            min_diff = min(min_diff, abs(root->val-prev));
        }
        prev = root->val;
        inorder(root->right, min_diff, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        int prev = -1;
        inorder(root, min_diff, prev);
        return min_diff;
    }
};