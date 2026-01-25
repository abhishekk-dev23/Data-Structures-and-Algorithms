class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int totalOcurrence = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == x){
                totalOcurrence++;
                mp[totalOcurrence] = i;
            }
        }

        for(int i=0; i<queries.size(); i++) {
            if(queries[i] > totalOcurrence){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[queries[i]]);
            }
        }
        return ans;
    }
};