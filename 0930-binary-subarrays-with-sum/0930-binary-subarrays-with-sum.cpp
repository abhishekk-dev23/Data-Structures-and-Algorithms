class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int count = 0;
        int sum = 0;
        mp[0] = 1;
        while(r < nums.size()) {
            sum += nums[r];
            int rem = sum - goal;
            count += mp[rem];
            mp[sum]++;
            r++;
        }

        return count;
    }
};