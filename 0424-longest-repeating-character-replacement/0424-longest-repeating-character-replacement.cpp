class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int max_len = 0;
        int max_freq = 0;
        vector<int> freq(26, 0);

        while(r < s.size()) {
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r]-'A']);

            while((r-l+1) - max_freq > k) {
                freq[s[l]-'A']--;
                max_freq = 0;
                for(int i=0; i<26; i++) {
                    max_freq = max(max_freq, freq[i]);
                }
                l++;
            }
            if((r-l+1) - max_freq <= k){
                max_len = max(max_len, r-l+1);
            }
            r++;
        }
        return max_len;
    }
};