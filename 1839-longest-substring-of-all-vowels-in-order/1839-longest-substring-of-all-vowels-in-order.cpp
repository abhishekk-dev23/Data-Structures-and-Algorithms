class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int len = 1;
        int max_len = 0;
        int count = 1;

        for(int i=1; i<n; i++) {
            if(word[i-1] <= word[i]){
                len++;
                if(word[i] != word[i-1]) count++;
            }
            else{
                len = 1;
                count = 1;
            }
            if(count == 5) max_len = max(max_len, len);
        }

        return max_len;
    }
};