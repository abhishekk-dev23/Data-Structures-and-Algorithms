class Solution {
public:
    int solve(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];

        vector<int> dp1(n);

        dp1[0] = arr[0];
        dp1[1] = max(arr[0], arr[1]);

        for(int i=2; i<n; i++) {
            int take = arr[i] + dp1[i-2];
            int skip = dp1[i-1];

            dp1[i] = max(take, skip);
        }
        return dp1[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> first, second;

        for(int i=0; i<n; i++) {
            if(i != n-1) first.push_back(nums[i]);
            if(i != 0) second.push_back(nums[i]);
        }

        return max(solve(first), solve(second));
    }
};