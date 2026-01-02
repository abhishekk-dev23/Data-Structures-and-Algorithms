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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        inorder(root, arr);   // sorted BST values

        vector<vector<int>> ans;

        for (int q : queries) {
            int n = arr.size();

            // first element >= q
            int idx = lower_bound(arr.begin(), arr.end(), q) - arr.begin();

            int mini, maxi;

            if (idx < n && arr[idx] == q) {
                mini = q;
                maxi = q;
            }
            else {
                // predecessor
                if (idx > 0) mini = arr[idx - 1];
                else mini = -1;

                // successor
                if (idx < n) maxi = arr[idx];
                else maxi = -1;
            }

            ans.push_back({mini, maxi});
        }

        return ans;
    }
};
