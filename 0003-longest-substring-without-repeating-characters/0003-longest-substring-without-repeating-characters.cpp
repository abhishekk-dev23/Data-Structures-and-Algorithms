class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int l = 0;
        unordered_set<int> st;

        for(int i=0; i<s.size(); i++) {
           while(st.count(s[i])) {
                st.erase(s[l]);
                l++;
           }
           st.insert(s[i]);
           max_len = max(max_len, i-l+1);
        }
        return max_len;
    }
};