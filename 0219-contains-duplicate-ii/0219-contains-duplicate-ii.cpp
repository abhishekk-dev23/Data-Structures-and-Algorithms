class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int l = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i-l > k) {
                st.erase(nums[l]);
                l++;
            }
            if(st.count(nums[i])){
                return true;
            }

            st.insert(nums[i]);
        }
        return false;
    }
};