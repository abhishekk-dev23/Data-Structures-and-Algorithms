class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l=0;
        int max_freq = 0;
        long long sum = 0;

        for(int r=0; r<n; r++) {
            sum += nums[r];

            while((long long)(r-l+1) * nums[r] - sum > k) {
                sum -= nums[l];
                l++;
            }
            max_freq = max(max_freq, (r-l+1));
        }
        return max_freq;
    }
};