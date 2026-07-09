class Solution {
public:
    int solveRob(int i, vector<int> &dp, vector<int> &nums) {
        if(i == 0) return nums[0];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solveRob(i-2, dp, nums);
        int skip = solveRob(i-1, dp, nums);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solveRob(n-1, dp, nums);
    }
};