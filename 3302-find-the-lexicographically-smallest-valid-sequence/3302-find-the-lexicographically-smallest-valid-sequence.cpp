class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();

        vector<int> suff(sz1, 0);

        int no_match = 0;
        int i = sz1-1;
        int j = sz2-1;

        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                no_match++;
                j--;
            }
            suff[i] = no_match;
            i--;
        }

        vector<int> v;
        bool changed = false;
        i = 0, j = 0;
        while(i < sz1 && j < sz2) {
            if(word1[i] == word2[j]) {
                v.push_back(i);
                j++;
            }
            else if(!changed && i+1 < sz1 && suff[i+1] >= sz2-1-j) {
                changed = true;
                v.push_back(i);
                j++;
            }
            i++;
        }
        if(j == sz2) return v;
        return {}; 
    }
};