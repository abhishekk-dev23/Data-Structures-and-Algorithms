class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int min_diff = INT_MAX;

        int one = -1, two = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                one = i;
                if(two != -1) {
                    min_diff = min(min_diff, abs(one - two));
                }
            }
            else if(nums[i] == 2) {
                two = i;
                if(one != -1) {
                    min_diff = min(min_diff, abs(one - two));
                }
            };
        }
        return (min_diff == INT_MAX) ? -1 : min_diff;
    }
};