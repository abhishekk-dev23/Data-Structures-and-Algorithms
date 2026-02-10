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
            // if(sum == goal) count++;

            int rem = sum - goal;
            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[sum]++;
            r++;
        }

        return count;
    }
};