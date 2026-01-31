class Solution {
public:
    bool checkDivisor(vector<int>& nums, int thres, int mid) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            int divis = (nums[i] + mid - 1) / mid;
            sum += divis;
            if(sum > thres) return false;
        }
        return thres >= sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;

        while(s <= e) {
            int mid = s + (e-s)/2;
            bool isDivisor = checkDivisor(nums, threshold, mid);

            if(isDivisor) {
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};