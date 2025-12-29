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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;


        while(!q.empty()) {
            long long size = q.size();
            long long levelSum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            minHeap.push(levelSum);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        if(minHeap.size() < k) return -1;
        return minHeap.top();
    }
};