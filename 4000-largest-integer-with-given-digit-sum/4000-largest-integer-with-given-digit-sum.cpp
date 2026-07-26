class Solution {
public: 
    int largestInteger(int n, int s) {
        if(s == 0) return 0;

        
        int ans = 0;
        int sum = s;
        
        while(n > 0) {
            int digit = min(9, sum);
            ans = ans * 10 + digit;
            sum = sum - digit;
            n--;
        }
        if(sum > 0) return -1;
        return ans;
    }
};