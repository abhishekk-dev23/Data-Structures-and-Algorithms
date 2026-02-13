class Solution {
public:
    int solve(vector<int>& nums, int goal) {
       if(goal < 0) return 0;
        int sum = 0;
        int l=0, r=0;
        int count = 0;

        while(r < nums.size()) {
            sum += nums[r];
            while(sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] = nums[i]%2;
        }
        int res = solve(nums, k) - solve(nums, k-1);
        return res;
    }
};