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
    TreeNode* createTree(vector<int> &postorder, int &i, unordered_map<int, int> &mp, int s, int e) {
        if(s > e || i < 0) return NULL;

        int rootVal = postorder[i--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        root->right = createTree(postorder, i, mp, mid+1, e);
        root->left = createTree(postorder, i, mp, s, mid-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int postOrderIndex = postorder.size()-1;
        TreeNode* ans = createTree(postorder, postOrderIndex, mp, 0, inorder.size()-1);
        return ans;
    }
};