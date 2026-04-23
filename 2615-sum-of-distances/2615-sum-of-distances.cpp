class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]].push_back(i) ;
        }

        for(auto& [val, idx]: mpp) {
            int m = idx.size();
            if(m == 1) continue;

            long long total_sum = 0;
            for(auto it: idx) total_sum += it;
            
            long long prefSum = 0;
            for(int i=0; i<m; i++) {
                long long currIdx = idx[i];
                // lft
                long long left = 1LL * i * currIdx - prefSum;
                // rgt
                long long suffSum = total_sum - prefSum - currIdx;
                long long right = suffSum - 1LL*(m - i - 1) * currIdx;

                ans[currIdx] = left + right;
                prefSum += currIdx;
            }
        }
        return ans;
    }
};