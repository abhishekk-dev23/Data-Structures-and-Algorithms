class Solution {
private:
    bool findString(string word, vector<string>& dic) {
        
        for(int i=0; i<dic.size(); i++) {
            string str = dic[i];
            int cnt = 0;
            for(int j=0; j<str.size(); j++) {
                if(word[j] != str[j]) {
                    cnt++;
                }
            }
            if(cnt <= 2) return true;
        }
        return false;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for(auto it: queries) {
            if(findString(it, dictionary)) {
                res.push_back(it);
            }
        }
        return res;
        
    }
};