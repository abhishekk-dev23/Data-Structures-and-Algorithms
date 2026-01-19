class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        vector<int> res;

        for(int i=0; i<n; i++) {
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }
            else{
                positive.push_back(nums[i]);
            }
        }
        for(int i=0; i<positive.size(); i++) {
            int plus = positive[i];
            int minus = negative[i];
            res.push_back(plus);
            res.push_back(minus);
        }
        return res;

    }
};