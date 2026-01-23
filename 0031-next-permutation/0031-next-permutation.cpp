class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int targetIdx = -1;

        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                targetIdx = i;
                break;
            }
        }
        if(targetIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        if(targetIdx != -1) {
            for(int i=n-1; i>targetIdx; i--) {
                if(nums[i] > nums[targetIdx]){
                    swap(nums[i], nums[targetIdx]);
                    break;
                }
            }
        }
        reverse(nums.begin() + targetIdx + 1, nums.end());
    }
};