class Solution {
public:
    int solve(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];

        int p1 = 0, p2 = 0;
        
        for(int i=0; i<n; i++) {
            int take = arr[i] + p1;
            int skip = p2;

            int curr = max(take, skip);
            p1 = p2;
            p2 = curr;
        }
        return p2;
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