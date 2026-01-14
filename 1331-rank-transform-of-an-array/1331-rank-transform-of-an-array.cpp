class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n <= 0) return {};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push({arr[i], i});
        }
        int rank = 0;
        int prevVal = INT_MIN;
        while(!pq.empty()) {
            auto topVal = pq.top();
            pq.pop();
            
            if(topVal.first != prevVal){
                rank++;
            }
            arr[topVal.second] = rank;
            prevVal = topVal.first;
        }
        return arr;
    }
};