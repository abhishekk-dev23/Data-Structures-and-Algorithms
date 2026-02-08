class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int sum = 0;
        int no_ele = 0;

        for(int i=n-1; i>=0; i--) {
            if(no_ele > 0) {
                double avg = (double)sum / no_ele;
                if(nums[i] > avg) {
                    count++;
                }
            }
            no_ele++;
            sum += nums[i];
        }
        return count;
    }
};