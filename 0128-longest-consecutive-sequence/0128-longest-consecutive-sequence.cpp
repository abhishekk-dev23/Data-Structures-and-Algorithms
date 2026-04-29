class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int len = 0;

        for(auto& it: st) {
            if(st.find(it-1) == st.end()) {
                int curr = it;
                int count = 1;

                while(st.find(curr+1) != st.end()) {
                    curr++;
                    count++;
                }
                len = max(len, count);
            }
        }
        return len;
    }
};