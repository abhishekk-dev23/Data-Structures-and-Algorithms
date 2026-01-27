class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i < n) {
            if(i+1 < n && arr[i] < arr[i+1]) {
                i++;
            }
            else{
                break;
            }
        }
        if(i == 0 || i == n-1) return false;

        while(i < n) {
            if(i+1 < n && arr[i] > arr[i+1]) {
                i++;
            }
            else{
                break;
            }
        }
        return i == n-1;
    }
};