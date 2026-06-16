class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return true;
        if(arr[0] == 0) return false;

        int maxStep = arr[0];
        int step = arr[0];
        int jump = 1;

        for(int i=1; i<n; i++) {
            if(i == n-1) return true;

            maxStep = max(maxStep, i + arr[i]);
            step--;

            if(step == 0) {
                jump++;
                if(i >= maxStep) return false;
                step = maxStep - i;
            }
        }
        return false;
    }
};