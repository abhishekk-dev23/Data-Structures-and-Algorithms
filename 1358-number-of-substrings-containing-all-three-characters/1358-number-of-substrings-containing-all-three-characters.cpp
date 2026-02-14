class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int l=0;
        int n = s.size();
        vector<int> mp(3, 0);
        
        for(int r=0; r<n; r++){
            mp[s[r]-'a'] ++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                count = count + (n - r);
                mp[s[l]-'a']--;
                l++;
            }
        }
        return count;
    }
};