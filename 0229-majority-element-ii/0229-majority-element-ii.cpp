class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        //            (value, freq)
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        for(auto x : mp) {
            if(x.second > n/3){
                res.push_back(x.first);
            }
        }
        return res;
    }
};