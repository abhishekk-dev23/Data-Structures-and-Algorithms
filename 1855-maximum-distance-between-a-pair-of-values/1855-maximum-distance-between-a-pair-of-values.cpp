class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int min_dist = 0;
        int i=0, j=0;

        while(i < n1 && j < n2) {
            if(i <= j) {
                if(nums1[i] <= nums2[j]) {
                    min_dist = max(min_dist, j - i);
                    j++;
                }
                else{
                    i++;
                }
            }
            else{
                j++;
            }
        }
        return min_dist;
    }
};