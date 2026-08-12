class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        int withOutZero = 1;
        int withZero = 1;
        for(auto it : nums) {
            if(it != 0) {
                withOutZero *= it;
            }
            withZero *= it;
            if(it == 0) cnt++;
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                ans[i] = withZero / nums[i];
            }
            else if(nums[i] == 0) {
                if(cnt == 1) {
                    ans[i] = withOutZero;
                }
                else{
                    ans[i] = withZero;
                }
            }
            else{
                ans[i] = withZero / nums[i];
            }
        }
        return ans;
    }
};