class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
            if(nums[i] < mini) {
                mini = nums[i];
            }
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
        }
        vector<int> ans;
        for(int i=mini; i<=maxi; i++) {
            if(mp.find(i) == mp.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};