class Solution {
private: 
int mergeArr(vector<int>& nums, int s, int e) {
    int mid = s + (e - s) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    vector<int> left(l1);
    vector<int> right(l2);
    int mainIdx = s;

    for(int i=0; i<l1; i++) left[i] = nums[mainIdx++];
    mainIdx = mid + 1;
    for(int i=0; i<l2; i++) right[i] = nums[mainIdx++];

    int cnt = 0;
    int j = 0;
    for(int i=0; i<l1; i++) {
        while(j < l2 && (long long)(left[i] > 2LL * right[j])) {
            j++;
        }
        cnt += j;
    }

    int idx1 = 0, idx2 = 0;
    mainIdx = s;

    while(idx1 < l1 && idx2 < l2) {
        if(left[idx1] <= right[idx2]) {
            nums[mainIdx++] = left[idx1++];
        }
        else {
            nums[mainIdx++] = right[idx2++];
        }
    }
    while(idx1 < l1) nums[mainIdx++] = left[idx1++];
    while(idx2 < l2) nums[mainIdx++] = right[idx2++];

    return cnt;
}
int findPairs(vector<int>& nums, int s, int e) {
    if(s >= e) return 0;

    int mid = s + (e - s) / 2;
    int cnt = 0;

    cnt += findPairs(nums, s, mid);
    cnt += findPairs(nums, mid+1, e);

    cnt+= mergeArr(nums, s, e);

    return cnt;
}
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = findPairs(nums, 0, n-1);
        return cnt;
    }
};