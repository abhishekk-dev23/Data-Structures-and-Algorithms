class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int half = nums.size()/2;
        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }

        for(auto it: count) {
            if(it.second > half) {
                return it.first;
            }
        }
        return -1;
    }
};