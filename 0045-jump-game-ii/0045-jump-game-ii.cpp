class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        if(nums[0] == 0) return 0;

        int max_reach = nums[0];
        int step = nums[0];
        int jumps = 1;

        for(int i=1; i<n; i++) {
            if(i == n-1) return jumps;

            max_reach = max(max_reach, i+nums[i]);
            step--;

            if(step == 0) {
                step = max_reach - i;
                if(i >= max_reach) return -1;
                jumps++;
            }
        }
        return -1;
    }
};