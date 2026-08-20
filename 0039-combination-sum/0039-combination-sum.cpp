class Solution {
private:
    void findSub(int idx, int t, vector<vector<int>> &ans, vector<int> temp, vector<int>& cand)
    {
        if(t == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<cand.size(); i++) {
            if(cand[i] > t) break;

            temp.push_back(cand[i]);
            findSub(i, t-cand[i], ans, temp, cand);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(cand.begin(), cand.end());

        findSub(0, tar, ans, temp, cand);

        return ans;
    }
};