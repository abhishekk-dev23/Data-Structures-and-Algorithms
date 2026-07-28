class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;

        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        string ans = "";
        ans.resize(n);

        int start = 0, end = n-1;

        for(int i=0; i<26; i++) {
            char ch = 'a' + i;

            if(freq[i] % 2 == 1) {
                ans[n/2] = ch;
                freq[i]--;
            }
            while(freq[i] > 0) {
                
                ans[start++] = ch;
                ans[end--] = ch;

                freq[i] -= 2;
            }
        }
        return ans;
    }
};