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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return true;
        vector<int> v;
        TreeNode* temp = root;
        stack<TreeNode*> s;
        while(temp != NULL || !s.empty()) {
            while(temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            v.push_back(temp->val);

            temp = temp->right;
        }
        int i=0, j=v.size()-1;
        while(i < j) {
            if(v[i] + v[j] < k){
                i++;
            }
            else if(v[i] + v[j] > k){
                j--;
            }
            else return true;
        }
        return false;

    }
};