#include<queue>

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        auto helper = [](string &a, string &b) {
            if(a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
        };


        priority_queue<string, vector<string>, decltype(helper)> pq(helper);

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};