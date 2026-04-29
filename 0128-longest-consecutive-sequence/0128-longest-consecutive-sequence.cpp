class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());

        int len = 1;
        int max_len = 1;

        for(int i=0; i<n-1; i++) {
            if(nums[i+1] - nums[i] == 1) {
                len++;
            }
            else if(nums[i+1] - nums[i] > 1){
                len = 1;
            }
            else continue;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};