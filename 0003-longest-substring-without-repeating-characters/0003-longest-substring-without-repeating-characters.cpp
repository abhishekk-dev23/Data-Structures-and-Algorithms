class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int max_len = 0;
        int l = 0;

        for(int r=0; r<s.size(); r++) {
            
            if(freq[s[r]] >= l){
                l = freq[s[r]] + 1;
            }
            
            max_len = max(max_len, r-l+1);
            freq[s[r]] = r;
        }
        return max_len;
    }
};