class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();

                    int ans = 0;
                    if(tokens[i] == "+") ans = a + b;
                    else if(tokens[i] == "-") ans = a - b;
                    else if(tokens[i] == "*") ans = a * b;
                    else ans = a / b;

                    st.push(ans);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};