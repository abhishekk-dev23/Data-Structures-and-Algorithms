class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_ele = INT_MAX;
        int s = 0, e = nums.size()-1;
        while(s <= e) {
            int mid = s + (e - s)/2;
            if(nums[s] <= nums[mid] && nums[mid] > nums[e]) {
                min_ele = min(min_ele, nums[mid]);
                s = mid + 1;
            }
            else{
                min_ele = min(min_ele, nums[mid]);
                e = mid-1;
                
            }
        }
        return min_ele;
    }
};