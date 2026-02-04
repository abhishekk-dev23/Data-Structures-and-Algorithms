class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_len = 0;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        for(auto x: freq) {
            int key = x.first;

            if(freq.find(key+1) != freq.end()){
                int len = x.second + freq[key+1];
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};