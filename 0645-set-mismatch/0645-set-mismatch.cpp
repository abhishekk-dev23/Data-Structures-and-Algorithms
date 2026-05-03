class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        int miss = -1;
        int rep = -1;
        for(int i=0; i<n; i++) {
            if(mp.find(i+1) != mp.end() && mp[i+1] == 2) rep = i+1;
            else if(mp.find(i+1) == mp.end()) miss = i+1; 
        }
        return {rep, miss};
    }
};