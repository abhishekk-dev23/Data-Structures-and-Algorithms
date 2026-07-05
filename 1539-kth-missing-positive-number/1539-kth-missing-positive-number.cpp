class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 1;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] != cnt){
                k--;
                i--;
                if(k == 0) break;
            }
            cnt++;
        }
        if(k != 0) cnt--;
        while(k > 0){
            cnt++;
            k--;
        }
        return cnt;
    }
};