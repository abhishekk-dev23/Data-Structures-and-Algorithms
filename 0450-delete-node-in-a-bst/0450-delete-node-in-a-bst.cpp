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
    TreeNode* succesor(TreeNode* root) {
        TreeNode* curr = root;
        if(root->right) curr = curr->right;

        while(curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        TreeNode* curr = root;

        
        if(key < curr->val){
            curr->left = deleteNode(curr->left, key);
        }
        else if(key > curr->val){
            curr->right = deleteNode(curr->right, key);
        }
        else{
            // 0 or 1 child
            if(curr->left == NULL){
                TreeNode* temp = curr->right;
                delete curr;
                return temp;
            }
            else if(curr->right == NULL){
                TreeNode* temp = curr->left;
                delete curr;
                return temp;
            }
            else{
                TreeNode* succ = succesor(curr);
                curr->val = succ->val;
                curr->right = deleteNode(curr->right, succ->val);
            }
        }
        
        return root;
    }
};