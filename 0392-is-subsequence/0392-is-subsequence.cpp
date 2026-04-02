class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;

        int cnt = 0;
        while(s.size() > i && t.size() > j) {
            if(s[i] == t[j]) {
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        if(cnt == s.size()) return true;
        return false;
    }
};