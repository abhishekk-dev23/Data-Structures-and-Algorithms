class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long mid = 0;

        while(s <= e) {
             mid = (s + e)/2;

            if(mid*mid == x) return mid;

            if(mid*mid > x) {
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return e;
    }
};