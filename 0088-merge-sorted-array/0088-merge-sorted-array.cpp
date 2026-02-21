class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastIdx1 = m - 1;
        int lastIdx2 = n - 1;
        int lastIdx = m+n-1;

        while(lastIdx1 >= 0 && lastIdx2 >= 0) {
            if(nums1[lastIdx1] > nums2[lastIdx2]) {
                nums1[lastIdx] = nums1[lastIdx1];
                lastIdx1--;
            }
            else{
                nums1[lastIdx] = nums2[lastIdx2];
                lastIdx2--;
            }
            lastIdx--;
        }
        while(lastIdx2 >= 0) {
            nums1[lastIdx] = nums2[lastIdx2];
            lastIdx--;
            lastIdx2--;
        }
    }
};