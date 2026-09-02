class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalSize = n1 + n2;

        vector<int> num;
        int i=0, j=0;
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                num.push_back(nums1[i]);
                i++;
            }
            else{
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1) {
            num.push_back(nums1[i]);
            i++;
        }
        while(j < n2) {
            num.push_back(nums2[j]);
            j++;
        }

        double ans = 0;
        int sz = totalSize / 2;

        if(totalSize % 2 == 0){
            double sum = num[sz-1] + num[sz];
            ans = sum / 2;
        }
        else{
            double sum = num[sz];
            ans = sum;
        }
        
        return ans;
    }
};