class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;

        for(char ch : s) {
            if(s.empty()) {
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == ch) {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};