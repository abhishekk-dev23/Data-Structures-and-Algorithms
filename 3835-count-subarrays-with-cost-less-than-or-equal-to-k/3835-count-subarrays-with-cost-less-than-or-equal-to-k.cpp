class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> minq, maxq;
        long long ans = 0;
        int l = 0;
        
        for(int r=0; r<nums.size(); r++) {
            while(!minq.empty() && nums[minq.back()] >= nums[r]) 
                minq.pop_back();
            minq.push_back(r);

            while(!maxq.empty() && nums[maxq.back()] <= nums[r])
                maxq.pop_back();
            maxq.push_back(r);


            while((long long)(nums[maxq.front()] - nums[minq.front()]) * (r - l + 1) > k) {
                if(maxq.front() == l) maxq.pop_front();
                if(minq.front() == l) minq.pop_front();

                l++; 
            }

            ans += (r - l + 1);
            
        }
        return ans;
    }
};