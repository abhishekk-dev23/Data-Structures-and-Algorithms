class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max_ele = nums[0];
        int min_ele = 0;
        int n = nums.size();
    
        for(int i=0; i<n; i++) {
            max_ele = max(max_ele, nums[i]);
            min_ele = *min_element(nums.begin()+i, nums.end());
            
            if(max_ele - min_ele <= k) return i;
            
        }
        return -1;
    }
};