class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

    // min-heap: {value, listIndex, elementIndex}
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;

        int currentMax = INT_MIN;
        
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while(true) {
            auto top = pq.top();
            pq.pop();

            int currentMin = top[0];
            int listIdx = top[1];
            int elemIdx = top[2];

            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            if (elemIdx + 1 == nums[listIdx].size()) {
                break;  
            }

            int nextVal = nums[listIdx][elemIdx + 1];
            pq.push({nextVal, listIdx, elemIdx + 1});
            currentMax = max(currentMax, nextVal);
        }
        return {rangeStart, rangeEnd};
    }
};