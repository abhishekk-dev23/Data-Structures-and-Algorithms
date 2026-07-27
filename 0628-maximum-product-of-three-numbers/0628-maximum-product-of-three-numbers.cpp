class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for(int x : nums) {
            // 3 max ke liye
            if(max1 < x) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if(max2 < x){
                max3 = max2;
                max2 = x;
            }
            else if(max3 < x) {
                max3 = x;
            }

            // 2 mini ke liye
            if(x < min1) {
                min2 = min1;
                min1 = x;
            }
            else if(x < min2){
                min2 = x;
            }
        }

        return max(max1*max2*max3, min1*min2*max1);
    }
};