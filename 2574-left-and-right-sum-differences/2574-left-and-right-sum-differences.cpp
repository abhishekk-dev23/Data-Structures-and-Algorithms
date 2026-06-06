class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int lftSum = 0;
        int rgtSum = 0;

        for(int i=0; i<n; i++) {
            if(i != 0) left[i] = lftSum;
            if(n-i-1 != n-1) right[n-i-1] = rgtSum;

            lftSum += nums[i];
            rgtSum += nums[n-i-1];
        }

        for(int i=0; i<n; i++) {
            int diff = abs(left[i] - right[i]);
            res[i] = diff;
        }
        return res;

    }
};