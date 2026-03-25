class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string> str(wordList.begin(), wordList.end());
        
        if(!str.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        str.erase(beginWord);

        while(!q.empty()) {
            auto [s, l] = q.front();
            q.pop();

            if(s == endWord) return l;

            // checking all value of word from a-z
            for(int i=0; i<s.size(); i++) {
                char original = s[i];

                for(char ch='a'; ch<='z'; ch++) {
                    s[i] = ch;
                    if(str.count(s)) {
                        q.push({s, l+1});
                        str.erase(s);
                    }
                }
                s[i] = original;
            }
        }
        return 0;
    }
};