class Solution {
public:
    bool miniDays(vector<int>& nums, int day, int mid) {
        int d = 1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] + sum > mid) {
                d++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
        }
        return d <= day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = s;

        while(s <= e) {
            int mid = s + ( e - s) / 2;

            if(miniDays(weights, days, mid)) {
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