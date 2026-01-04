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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == NULL) return root = node;
        
        TreeNode* curr = root;
        while(curr != NULL) {
            
            if(val < curr->val){
                if(curr->left == NULL){
                    curr->left = node;
                    break;
                }
                curr = curr->left;
            }
            else if(val > curr->val){
                if(curr->right == NULL){
                    curr->right = node;
                    break;
                } 
                curr = curr->right;
            }
        }
        return root;
    }
};