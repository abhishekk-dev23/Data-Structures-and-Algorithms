class Solution {
private:
    void findSub(int idx, int t, vector<int>& cand, vector<vector<int>> &ans, vector<int> &temp) 
    {
        if(t == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<cand.size(); i++) {
            if(i > idx && cand[i] == cand[i-1]) continue;

            if(cand[i] > t) break;

            temp.push_back(cand[i]);
            findSub(i+1, t-cand[i], cand, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {

        int n = cand.size();
        sort(cand.begin(), cand.end());

        vector<vector<int>> ans;
        vector<int> temp;

        findSub(0, t, cand, ans, temp);

        return ans;
    }
};