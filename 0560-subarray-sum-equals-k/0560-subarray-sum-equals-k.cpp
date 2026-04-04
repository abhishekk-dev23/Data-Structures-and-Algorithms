class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        int preSum = 0;
        mpp[0] = 1;
        int count = 0;

        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            count += mpp[preSum - k];
            
            mpp[preSum]++;
        }
        
        return count;
    }
};