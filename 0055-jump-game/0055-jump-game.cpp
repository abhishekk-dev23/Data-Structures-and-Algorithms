class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return true;
        if(arr[0] == 0) return false;

        int maxStep = 0;

        for(int i=0; i<n; i++) {
            if(i > maxStep) return false;

            maxStep = max(maxStep, i + arr[i]);
        }
        return true;
    }
};