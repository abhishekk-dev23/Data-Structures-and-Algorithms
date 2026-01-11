class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x : stones){
            pq.push(x);
        }

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int leftStone = y - x;
            if(y != x){
                pq.push(leftStone);
            }
        }
        
        int ans = !pq.empty() ? pq.top() : 0;
        return ans;
    }
};