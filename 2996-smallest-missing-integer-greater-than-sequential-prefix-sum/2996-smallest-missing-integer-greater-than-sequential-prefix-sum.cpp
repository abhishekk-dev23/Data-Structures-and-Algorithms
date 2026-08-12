class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i] - 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }
        set<int> st;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= sum) st.insert(nums[i]);
        }
        int cnt = sum;
        for(int i=0; i<nums.size(); i++) {
            if(st.find(cnt) == st.end()) {
                return cnt;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};