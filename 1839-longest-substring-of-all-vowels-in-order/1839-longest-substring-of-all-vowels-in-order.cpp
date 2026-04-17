class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int len = 1;
        int max_len = 0;
        int count = 1;

        for(int i=1; i<n; i++) {
             if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
                len = 1;
                count = 1;
                continue;
            }
            if(word[i] >= word[i-1]){
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