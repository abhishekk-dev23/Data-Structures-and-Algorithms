class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<int> mp(3, -1);
        
        for(int r=0; r<n; r++){
            mp[s[r]-'a'] = r;

            if(mp[0] != -1 && mp[1] != -1 && mp[2] != -1) {
                count = count + (1 + min(mp[0], min(mp[1], mp[2])));
            }
        }
        return count;
    }
};