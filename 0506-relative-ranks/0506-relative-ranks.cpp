class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++) {
            pq.push({score[i], i});
        }
        int count = 0;
        while(!pq.empty()) {
            auto val = pq.top();
            pq.pop();
            count++;

            if(count == 1){
                ans[val.second] = "Gold Medal";
            }
            else if(count == 2){
                ans[val.second] = "Silver Medal";
            }
            else if(count == 3){
                ans[val.second] = "Bronze Medal";
            }
            else{
                ans[val.second] = to_string(count);
            }
        }
        return ans;
    }
};