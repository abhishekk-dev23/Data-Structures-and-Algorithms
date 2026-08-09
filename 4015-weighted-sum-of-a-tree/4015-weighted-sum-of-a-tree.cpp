class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> child(n);
        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = i;
            } else {
                child[parent[i]].push_back(i);
            }
        }

        vector<int> depth(n, 0);
        queue<int> q;

        q.push(root);
        depth[root] = 1;
        int maxDepth = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth[curr]);

            for (int c : child[curr]) {
                depth[c] = depth[curr] + 1;
                q.push(c);
            }
        }

        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            long long weight = maxDepth - depth[i] + 1;
            totalSum += weight * nums[i];
        }

        return totalSum;
    }
};