class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        nums.clear();
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            nums.push_back(top);
        }
        return nums;
    }
};