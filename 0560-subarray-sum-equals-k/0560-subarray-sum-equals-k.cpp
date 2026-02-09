class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int preSum = 0;
        mpp[0] = 1;
        int count = 0;

        for(int i=0; i<n; i++) {
            preSum += nums[i];
            int remove = preSum - k;
            count += mpp[remove];

            int rem = preSum - k;
            
            mpp[preSum]++;
        }
        
        return count;
    }
};