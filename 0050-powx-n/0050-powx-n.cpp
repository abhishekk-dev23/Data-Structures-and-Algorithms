class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double ans = 1.0;

        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        while(N > 0){
            if(N & 1) {
                ans = ans * x;
            }

            x = x * x;
            N = N >> 1;
        }
        return ans;
    }
};