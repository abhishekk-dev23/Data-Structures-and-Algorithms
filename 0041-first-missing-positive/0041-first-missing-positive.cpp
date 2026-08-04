class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> ans;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) ans.insert(nums[i]);
        }

        int j=0;
        for(int i=1; i<=ans.size(); i++) {
            if(ans.find(i) == ans.end()) {
                return i;
            }
            else{
                j++;
            }
        }
        return ans.size()+1;
    }
};