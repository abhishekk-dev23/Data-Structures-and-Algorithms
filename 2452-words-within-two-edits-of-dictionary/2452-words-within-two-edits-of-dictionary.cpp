class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for(auto it: queries) {
            string wo = it;
            for(int i=0; i<dictionary.size(); i++) {
                int cnt = 0;
                string str = dictionary[i];
                for(int j=0; j<str.size(); j++) {
                    if(str[j] != wo[j]) cnt++;
                    if(cnt > 2) break;
                }
                if(cnt <= 2) {
                    res.push_back(it);
                    break;
                };
            }
        }
        return res;
        
    }
};