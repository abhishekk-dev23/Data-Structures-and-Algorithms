class Solution {
public:
    void heapify(vector<int> &nums, int n, int i) {
        while(true){
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(l < n && nums[l] > nums[largest]){
                largest = l;
            }
            if(r < n && nums[r] > nums[largest]) {
                largest = r;
            }
            if(largest == i){
                break;
            }
            swap(nums[i], nums[largest]);
            i = largest;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=(n/2-1); i>=0; i--) {
            heapify(nums, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};