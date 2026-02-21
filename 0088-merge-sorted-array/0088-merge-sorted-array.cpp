class Solution {
public:
    void helperFun(vector<int>& nums, int x, int size) {
        nums[size] = x;
        for(int j=size; j>0; j--) {
            if(nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
            }
        } 
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<nums2.size(); i++) {
            int x = nums2[i];
            helperFun(nums1, x, m++);
        }
    }
};