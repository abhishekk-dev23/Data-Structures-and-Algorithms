class Solution {
private: 
    bool checkVow(string word, int s, int e) {
        string str = "aeiou";
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        set<char> st;
        for(int i=s; i<=e; i++) {
            if(vowels.find(word[i]) == vowels.end()) return false;
            st.insert(word[i]);
        }
        
        return st.size() == 5;
    }
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(j - i + 1 >= 5 && checkVow(word, i, j)) {
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};