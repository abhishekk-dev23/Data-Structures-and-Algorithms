class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;

        for(auto it: nums) mp[it]++;
        
        for(int i=0; i<nums.size(); i++) {
            if(mp[nums[i]] <= 1) {
                if(mp.find(nums[i]+1) == mp.end() &&
                    mp.find(nums[i]-1) == mp.end()) {
                        res.push_back(nums[i]);
                }
            }
        }
        return res;
    }
};