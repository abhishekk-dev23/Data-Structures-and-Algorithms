class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i<n; i++) {
            set<char> st;
            
            for(int j=i; j<n; j++) {
                if(vowels.find(word[j]) == vowels.end()) break; 
                st.insert(word[j]);
                if(st.size() == 5) cnt++;
            }
        }
        return cnt;
    }
};