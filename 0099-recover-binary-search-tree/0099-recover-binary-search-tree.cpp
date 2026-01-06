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
    void InOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }
    void CreateTree(TreeNode* root, vector<int> &ans, int &i) {
        if(root == NULL) return;
        if(i >= ans.size()) return;

        CreateTree(root->left, ans, i);
        root->val = ans[i++];
        CreateTree(root->right, ans, i);
    }
    void recoverTree(TreeNode* &root) {
        vector<int> ans;
        if(root == NULL) return;
        InOrder(root, ans);
        sort(ans.begin(), ans.end());
        int i=0;
        CreateTree(root, ans, i);
    }
};