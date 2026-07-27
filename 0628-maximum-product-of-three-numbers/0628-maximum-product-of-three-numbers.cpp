class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return nums[0]*nums[1]*nums[2];

        sort(nums.begin(), nums.end());

        int max1 = 1;
        int max2 = 1;

        max1 = nums[n-1]*nums[n-2]*nums[n-3];
        max2 = nums[0]*nums[1]*nums[n-1];
        
        return max(max1, max2);
    }
};