class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0; 
        int val = i+1;
        while(k > 0) {
            if(i < arr.size() && arr[i] == val ) {
                i++;
            }
            else{
                k--;
            }
            val++;
        }
        return val-1;
    }
};