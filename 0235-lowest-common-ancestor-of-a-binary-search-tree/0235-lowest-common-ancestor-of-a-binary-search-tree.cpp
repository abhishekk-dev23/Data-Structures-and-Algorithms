/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* Ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        TreeNode* leftLCA = NULL;
        TreeNode* rightLCA = NULL;
        if(root->val > p->val && root->val > q->val) {
            leftLCA = Ancestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val){
            rightLCA = Ancestor(root->right, p, q);
        }
        else if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)){
            return root;
        }
        

        if(leftLCA && rightLCA) return root;
        else if(!leftLCA) return rightLCA;
        else return leftLCA;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Ancestor(root, p, q);
    }
};