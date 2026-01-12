class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++) {
            pq.push(nums[i]);
        }
        for(int i=k; i<n; i++) {
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};