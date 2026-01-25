class Solution {
private:
    void solve(vector<int>& nums, int target, int s, int e, int &index){
        if(s > e){
            return ;
        }
        int mid = s + (e-s)/2;

        if(nums[mid] >= target){
            index = mid;
            solve(nums, target, s, mid-1, index);
        }
        else if(nums[mid] < target){
            solve(nums, target, mid+1, e, index);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int index = n;
        solve(nums, target, 0, n-1, index);

        return index;
    }
};