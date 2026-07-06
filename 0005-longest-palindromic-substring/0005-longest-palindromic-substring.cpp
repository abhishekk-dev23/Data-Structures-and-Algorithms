class Solution {
public:
    int expendStr(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 0;

        for(int i=0; i<s.size(); i++) {
            // for odd len string
            int len1 = expendStr(s, i, i);
            // for even len string
            int len2 = expendStr(s, i, i+1);

            int len = max(len1, len2);

            if(len > max_len) {
                max_len = len;

                start = i - (max_len - 1) / 2;
            }
        }
        return s.substr(start, max_len);
    }
};