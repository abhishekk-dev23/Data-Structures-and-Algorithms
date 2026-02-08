class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for(int i=0; i<nums.size(); i++) {
            long long curr = nums[i];
            while(!st.empty() && curr == st.top()) {
                curr += st.top();
                st.pop();

            }
            st.push(curr);
        }

        vector<long long> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};