class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;

        for(auto x: nums) {
            long long curr = x;

            while(!res.empty() && curr == res.back()) {
                curr += res.back();
                res.pop_back();
            }
            res.push_back(curr);
        }   
        return res;
    }
};