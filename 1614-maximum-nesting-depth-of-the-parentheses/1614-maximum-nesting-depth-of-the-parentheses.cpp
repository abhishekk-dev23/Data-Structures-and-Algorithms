class Solution {
public:
    int maxDepth(string s) {
        int par = 0;
        int max_par = 0;

        for(auto ch : s) {
            if(ch == '('){
                par++;
                max_par = max(max_par, par);
            }
            else if(ch == ')'){
                par--;
            }
        }
        return max_par;
    }
};