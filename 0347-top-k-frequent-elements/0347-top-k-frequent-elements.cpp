class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //pair for storing {freq, val}
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

        unordered_map<int, int> mp;
        // map for strong {val, freq}
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto v : mp) {
            pq.push({v.second, v.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        for(int i=0; i<k; i++) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        return res;
    }
};