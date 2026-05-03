class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        if(n == 1) return {0};

        int evn = 0;
        int odd = 0;
        res[n-1] = 0;

        for(int i=n-1; i>=0; i--) {
            if(nums[i]%2 == 0) {
                res[i] = odd;
                evn++;
            }
            else{
                res[i] = evn;
                odd++;
            }
        }
        return res;
    }
};