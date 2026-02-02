class Solution {
public:
    int checkSplitArray(vector<int>& nums, int k, int max_sum) {
        int sum = 0;
        int no_of_subarray = 1;

        for(auto x: nums) {
            if(sum + x > max_sum) {
                sum = x;
                no_of_subarray++;
            }
            else{
                sum += x;
            }
        }
        return no_of_subarray <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            bool isPossible = checkSplitArray(nums, k, mid);

            if(isPossible) {
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