class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zer = 0;
        int one = 0;
        int max_one = INT_MIN;

        for(auto x : nums) {
            if(x == 1) {
                one++;
            }
            else{
                max_one = max(max_one, one);
                one = 0;
            }
        }
        max_one = max(max_one, one);
        return max_one;
    }
};